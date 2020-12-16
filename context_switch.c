// Miguelangel Rodriguez and Maria Martinez
// The main purpose for this program is to understand the cost of a context switch and to 
//develop a better idea on how the OS manages to switch processes from one state to the other
// by using the blocking state   
#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
char* ms3 = "pipe 5 testSTR1ing ";
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
char* ms1 = "pipe 1 testSTR1ing ";
char* ms2 = "adding part2 ";
#define MSGSIZE 16



int main()
{
    //setting the program to run in one processor by using sched_setaffinity()
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0,&set);
    if(sched_setaffinity(getpid(),sizeof(cpu_set_t),&set))
     {
         exit(EXIT_FAILURE);
     }

    // time struct to keep track of the start and end time.
    struct timeval start, end;
    char inbuf[MSGSIZE];
    int P1[2];
    int P2[2];
    int P3[2];
    int n;
    int memoryIM;
    n = 1000;
    
    //checking if Pipe 1 was susscefully created 
    if (pipe(P1)== -1)
        {
            fprintf(stderr, "Pipe 1 Failed" ); 
                     return 1;
        }
    //checking if Pipe 2 was susscefully created 
    if(pipe(P2) == -1)
        {
            fprintf(stderr, "Pipe 2 Failed" ); 
                     return 1;
        }
    int syscallsnum;
    syscallsnum = 2;
    //checking if Pipe 3 was susscefully created 
    if(pipe(P3) == -1)
        {
            fprintf(stderr, "Pipe 2 Failed" ); 
                     return 1;
        }

    int i;
    char buffLoad[100];
    char buffRd[100];
    int value = -1;
    char testSTR1[] = "for teststring 1";
    char testSTR2[] = "for teststring 2";
    double finalTime; 
    int maxiteration;
    maxiteration = 100000;
     float execution;
     //checking if fork run with no issues
    if((value = fork()) < 0)
        {
            printf("Error at Fork");
            return 1;
        }
    else if(value == 0)
        {
            
            for(i=0;i<maxiteration;i++)
                {
                    read(P1[0],buffLoad,sizeof(buffLoad));//reading from p1
                    write(P2[1], testSTR1, strlen(testSTR1)+1);//writting p2 tostr
                }
        
            gettimeofday(&end, NULL);
            write(P3[1],&end,sizeof(struct timeval));

        }
    else{
            gettimeofday(&start, NULL);
            for(i=0;i<maxiteration;i++)
                {
                    write(P1[1], testSTR2, strlen(testSTR2)+1); // writting p1 str
                    read(P2[0],buffRd,sizeof(buffRd)); //reading p2tobff
                }

            read(P3[0],&end,sizeof(struct timeval));
            wait(NULL);
            finalTime = ((end.tv_sec-start.tv_sec)*1000000 +(end.tv_usec-start.tv_usec));
            execution = finalTime / (maxiteration*syscallsnum);
            printf(" The chill and parent proccess time of execution for the context switch is: %0.6lfµs\n",execution);
         }

    //  write(P1[1], ms1, MSGSIZE);
    //  gettimeofday(&start, NULL);
    //  write(P1[1], ms2, MSGSIZE);
    //  gettimeofday(&end, NULL);


    
    
    // finalTime= ((end.tv_usec - start.tv_usec));
    // double timetoexec = 0;
    // timetoexec = finalTime / n;
    // printf("The program takes %f to be execute\n", finalTime); 
    // printf("Average Execution time: %f",timetoexec);

    
    
    //  for (i = 0; i < 3; i++)
    //   { 
    //     /* read pipe */
    //     read(P1[0], inbuf, MSGSIZE); 
    //     printf("%s\n", inbuf); 
    // }
    

   // printf("terminating");
return 0;
}