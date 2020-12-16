// Miguelangel Rodriguez and Maria Martinez
// The main purpose for this program is to calculate the average execution time for a syscall. We are going to acomplish this by 
// using the gettimeoftheday() function and recording the start time before the execution and the end time after the execution of
// the syscall. then we will calculate the total execution time by substracting final time  minus start time. subsequenly we will
// divide it by the itteration times in order to obtain the average execution time. we perforn this operation with a big sample size
// in order to obtain a more acurate, average execution time. 
#include "string.h"
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include <sys/time.h> 

int main(void)
{ 
    // time struct to keep track of the start and end time.
    struct timeval start, end;
    
    // start= clock();
    
    //File * fp;

    int time;
   int i; 
    int n= 10000;
    wait(NULL);
    //sleep(3);
    gettimeofday(&start, NULL);//getting time of the day start
    //printf(" start of the clock is: %6.3ld\n", start);
    for (i=0; i< n; i++)
    {
        //int OP = open("text1.txt",O_RDONLY, 0)
        write( 1,"Operating system is fun\n", 24);
        
    } 
    gettimeofday(&end, NULL);// getting time of the day end
    // end= clock(); 
    printf("the end of the clock is %6.3ld\n", end);
    // float clockpersec;
    // clockpersec = CLOCKS_PER_SEC;
    float finalTime; 
    finalTime= (end.tv_usec - start.tv_usec);
    float timetoexec = 0;
    //printf("final time: %f\n", finalTime); 
    timetoexec = finalTime / n;
    printf("The program takes %fµs to be executed\n", finalTime); 
    printf("Average Execution time: %fµs\n",timetoexec);
    return 0; 
  
   
  
   
  
    
  
    

}
    