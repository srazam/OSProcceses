#include <stdio.h> 
#include <unistd.h> //fork and pid functions
#include <stdlib.h> // pipe() function
#include <string.h> //strnlen() functions
#include <ctype.h> //.isupper(), .toupper(), and .tolower() functions
 
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1
 
int main() {
    char write_msg[BUFFER_SIZE]; //Message that's written
    char read_msg[BUFFER_SIZE]; //Message that's read
    
    //Initializing two pipes
    int fd[2]; 
    int fd2[2];
    pid_t pid;
 
    //Checking if either pipe failes
    if ((pipe(fd) == -1) || (pipe(fd2) == -1)) {
        printf("Pipe failed\n");
    }
 
    // Fork a child process
    pid = fork();
 
    // If a fork fails
    if (pid < 0) {
        printf("Fork failed\n");
    }
 
    // Parent Process
    if (pid > 0) {
        // Close the unused read end of the first pipe
        close(fd[READ_END]);

        //Input message and set it to the write_msg 
        printf("Enter a message: ");
        scanf("%[^\n]%*c", write_msg); //Taking into account spaces
 
        // Write to the first pipe the message just inputed
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);

        // Close the unused write end of the first pipe
        close(fd[WRITE_END]);
 
        // Close the unused write end of the secon dpipe
        close(fd2[WRITE_END]);

        //Read from the second pipe the updated message and display the message
        read(fd2[READ_END], read_msg, BUFFER_SIZE);
        printf("Parent Process received message: %s\n", read_msg);

        // Close the unused read end of the secon dpipe 
        close(fd2[READ_END]);
    }
    // Child Process
    else {
        // Close the unused write end of the first pipe
        close(fd[WRITE_END]);

        // Read from the first pipe the message that was inputted and display it
        read(fd[READ_END], write_msg, BUFFER_SIZE);
        printf("Child process is sending a message: %s\n", write_msg);

        //Close the unused read end of the first pipe
        close(fd[READ_END]);

        //Make each character from the write_msg to the opposite case
        for (int i = 0; i < sizeof(write_msg); i++)
        {
            if(isupper(write_msg[i]))
            {
                read_msg[i] = tolower(write_msg[i]);
            }
            else
            {
                read_msg[i] = toupper(write_msg[i]);
            }
        }

        //Close the unused read end of the second pipe
        close(fd2[READ_END]);

        // Write to the second pipe the updated message
        write(fd2[WRITE_END], read_msg, strlen(read_msg) + 1);
 
        // Close the unused write end of the second pipe
        close(fd2[WRITE_END]);
    }
 
    return 0;
}