#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


void search_file(const char *filename, const char *target, int start_line, int end_line) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: can be not opened.");
        exit(1);
    }
        
              char line[1024];
              int current_row = 1;
        
              while (fgets(line, sizeof(line), file)) {
                  if (current_row >= start_line && current_row <= end_line) {
                      char *ptr = strstr(line, target);
                      if (ptr != NULL) {
                          int col = (ptr - line) + 1; 
                          printf("Text found at row %d col %d\n", current_row, col);
                      }
                  }
                  current_row++;
                  if (current_row > end_line) break;
              }
        
              fclose(file);
}              

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("Usage: %s <filename> <search_string>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *target = argv[2];

   
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: not  found.");
        return 1;
    }

    int total_lines = 0;
    int ch; 
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            total_lines++;
        }
    }
    fclose(fp);

  
    if (total_lines == 0) {
        return 0;
    }

    int lines_per_child = total_lines / 4;

    
    for (int i = 0; i < 4; i++) {
        int start = i * lines_per_child + 1;
        int end = (i == 3) ? total_lines : (i + 1) * lines_per_child;

        pid_t pid = fork();

        if (pid == 0) {
          
            search_file(filename, target, start, end);
            exit(0); 
        }
    }

    
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}