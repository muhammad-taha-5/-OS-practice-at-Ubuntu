#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  main ( int arc, char *ars[] ){

    if (arc < 2) {
    printf("Usage: %s <name> \n", ars[1]);
    return 1;
    }
        char ch;
        printf("bhai character enter karo: ");
         scanf("%c", &ch);    
        printf("\nAapne ye character enter kiya hai: %c\n", ch);


          char *name = ars[1];
          int len = strlen(name);
            int  count =0;
          for(int i=0 ; i< len;  i++){
              if(ch == name[i]){
                count++;
               }
            }
           printf("Name: %s\n, Character: %c\n, Count: %d\n", name, ch, count);

          
    return 0;
 }


