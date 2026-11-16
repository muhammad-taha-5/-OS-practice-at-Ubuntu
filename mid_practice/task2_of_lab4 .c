// Write a C program that inputs N numbers from the user and passes N/2 numbers to each of its two child processes through pipes. 
// The child processes search their own list for the smallest number and send those numbers to their parent process through pipes. 
// The parent process finally prints the smallest of them

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
# define re 0;
# define wr 1;

int main(int argc ,char *argv[] ){
if(argc <=2 && argc %2 != 0 ){
prinf("enter the elemets of arr not  only 2:" );
return 1;
}

/*// if avoid  the  commmads line  arrgument !
int arr[n];
    printf("%d numbers enter karein:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    } *\

int  half = argc/2;
int  rem = argc - half;

int p1_in[2]; 
int p1_out[2];
int p2_in[2];
int p2_out[2];
// leave the  cheeks  
pid_t pid1= fork();
// leave the  cheeks

if(pid1 == 0){
close (p2_in[re]);
close (p2_out[wr]);
close (p2_in[wr]);
close (p2_out[re]);

close ( p1_in[wr]);
close ( p1_out[re]);
  
int arrsub1[half];
read(p1_in[re],arrsub1,half);
close(p1_in[re]);
  
int min1 = sub_arr1[0];
        for (int i = 1; i < half; i++) {
            if (sub_arr1[i] < min1) {
                min1 = sub_arr1[i];
            }
        }
  

write (p1_out[wr] &min1, sizeof(min1));
  close(p1_out[wr]);
  exit(0);
}


  pid_t pid2= fork();
// leave the  cheeks

if(pid2 == 0){
close (p1_in[re]);
close (p1_out[wr]);
close (p1_in[wr]);
close (p1_out[re]);

close ( p2_in[wr]);
close ( p2_out[re]);
  
int arrsub2[rem];
read(p2_in[re],arrsub2,rem);
close(p2_in[re]);
  
int min2 = sub_arr2[0];
        for (int i = 1; i < rem; i++) {
            if (sub_arr2[i] < min2) {
                min2 = sub_arr2[i];
            }
        }
  

write (p2_out[wr] &min2, sizeof(min2));
  close(p2_out[wr]);
  exit(0);
}


 close(p1_in[re]);
 close(p1_out[wr]);
 close(p2_in[re]);
close(p2_out[wr]);

  // parent  process !  // chi1
  write(p1_in[wr], atio(&argv[0]) half sizeof(int));
  close(p1_in[wr]);
int  ch1;
  read(p1_out[re],  &ch1 ,sizeof(ch1) );
 close(p1_out[re]);

  // chi2
 write(p2_in[wr], atio(&argv[half]) rem sizeof(int));
  close(p2_in[wr]);
int  ch2;
  read(p2_out[re],  &ch2 ,sizeof(ch2) );
 close(p2_out[re]);
   
  wait(NULL);
    wait(NULL);

   printf("\nChild 1 ka smallest: %d\n", child1_min);
    printf("Child 2 ka smallest: %d\n", child2_min);
    printf("Overall Smallest Number: %d\n", overall_min);
   
return 0;
}

