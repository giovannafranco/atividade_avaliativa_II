#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TRUE 1

int main(int argc, char *argv[])
{
    char *path = malloc(256);
    char *command = malloc(256);
    char *params = malloc(256);
	char *parameters[3];
    pid_t pid;
    int status;

    path = strcpy(path, "/bin/");  // initialize the default path of UNIX systems
    parameters[2] = NULL; // The last parameters of array is always NULL
    
	while (TRUE)
	{
	    pid = fork();
	    if (pid == 0)
	    {
	        printf("\n~$ ");
	        gets(command);
	        gets(params);
	        command = strcat(path, command);
	        parameters[0] = command;
            parameters[1] = params;
	        execve(command, parameters, NULL);
	    }
	    else
	    {
	        waitpid(-1, &status, 0);
	    }		
    }

	return 0;
}


