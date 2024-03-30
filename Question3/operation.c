#include <stdio.h>
#include <unistd.h> // fork, getpid
#include <sys/wait.h> // Wait function
#include <stdlib.h> //atoi function - used to get convert the input when running the program

int main(int argc, char *argv[]) {
    
    //Taking the number entered by the user
    char *a = argv[1];
    int n = atoi(a);
    
    //If a negative number is passed, end the program
    if (n < 0)
    {
        printf("Negative number entered \n");
        return 0;
    }

    // Fork a child process
    pid_t pid = fork();

    // Fork failed
    if (pid < 0) {
        printf("Fork failed");
        return 1;
    }
    // Child process
    else if (pid == 0) {

        //Generating sequence in child process 
        printf("%i ", n);
        while(n != 1)
        {
            //If n is even, n/2
            if(n % 2 == 0)
            {
                n = n/2;
                printf("%i ", n);
            }
            //If n is odd, 3n + 1
            else
            {
                n = (3 * n) + 1;
                printf("%i ", n);
            }
        }
        printf("\n");
    }
    // Parent Process - make the parent wait until the child process is compelte 
    else {
        wait(NULL);
    }
    return 0;
}