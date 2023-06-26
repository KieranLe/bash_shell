#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main( void )
{
    pid_t pid = fork();
    
    if( pid == -1) 
    {
        perror("fork failed: ");
        exit( EXIT_FAILURE );
    }
    else if( pid == 0 )
    {
        printf("Hello from the child process\n");
        fflush(NULL);
        exit( EXIT_SUCCESS );
    }
    else
    {
        int status;
        
        waitpid(pid, &status, 0);
        printf("Hello from the parent process \n");
        fflush(NULL);
    }
    
    return EXIT_SUCCESS;
}
