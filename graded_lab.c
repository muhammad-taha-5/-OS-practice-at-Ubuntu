#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int  main ( int arc ,char *ars[] ){

       if(arc <= 3 ){
         printf("Usage: %s <name1> <name2> <name3>\n", ars[0]);
          return 1;
       }

        for(int i=1 ; i<arc ;  i++){

            char *name = ars[i];
            int len =strlen(name);
            char f_latter = name[0];
            char l_latter = name [len-1];

              printf("name: %d : %s \n" ,i, name );
              printf("first_latter  %c\n" , f_latter);
              printf("first_latter  %c\n" , l_latter);
        } 
    return  0; 
 }

