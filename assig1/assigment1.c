#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <search_string>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *target = argv[2];

    // Total lines calculate karne ke liye file open
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File open nahi ho saki.\n");
        return 1;
    }

    int total_lines = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            total_lines++;
        }
    }
    fclose(fp);

    int lines_per_child = total_lines / 4;

    // 4 Child processes create karna
    for (int i = 0; i < 4; i++) {
        int start = i * lines_per_child + 1;
        int end = (i == 3) ? total_lines : (i + 1) * lines_per_child;

        pid_t pid = fork();

        if (pid == 0) {
            // Child process execution
            FILE *file = fopen(filename, "r");
            if (file != NULL) {
                char line[1024];
                int current_row = 1;

                while (fgets(line, sizeof(line), file)) {
                    if (current_row >= start && current_row <= end) {
                        char *ptr = strstr(line, target);
                        if (ptr != NULL) {
                            int col = (ptr - line) + 1;
                            printf("Text found at row %d col %d\n", current_row, col);
                        }
                    }
                    current_row++;
                }
                fclose(file);
            }
            exit(0); // Child exit
        }
    }

    // Parent wait karega sabhi children ke liye
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}