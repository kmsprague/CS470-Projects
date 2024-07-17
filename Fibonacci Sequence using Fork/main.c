/*In this program, we are calculating the Fibonacci Sequence using a parent process which gets how much of the sequence is to be printed and a child process to output the sequence*/

#include <stdio.h>  //standard input output
#include <sys/types.h> //process ID data type
#include <unistd.h> //to use fork()
#include <sys/wait.h>  //to use wait()


int main(){

    //variables
    int n0 = 0, n1 = 1, x, i;

    //getting the sequnece number
    printf("Enter the amount of sequnce numbers you'd like to see: "); 
    scanf("%d", &i);

    //making the new process 
    pid_t pid; 
    pid = fork(); 

    //Error handling for process creation 
    if(pid < 0){
        printf("Error with fork()!\n"); 
        return 1; 
    }

    //child process 
    else if(pid == 0){

        //handling non-negative or 0 input
        if(i <= 0){ 
            printf("Must be a non-negative, non-zero integer!\n"); 
            return 0; 
        }
        //handing i = 1
        else if(i ==1 ){
            printf("%d\n", n0); 
            return 0; 
        }
        
        //printing the first 2 numbers in sequence
        printf("%d\n%d\n", n0, n1); 

        while(i > 2){
            x = n1; 
            n1 = n0 +n1; 
            n0 = x; 
            printf("%d\n", n1); 
            i--; 
        }
        return 0; 
    }

    //Parent Process 
    else if(pid > 0){
        wait(NULL); 
        printf("Finished Printing"); 
        return 0; 
    }

    return 0; 
}