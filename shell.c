#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TRUE 1

void read_command(char *command, char *parameters[]);

int main(int argc, char *argv[])
{
    char *path = malloc(256);
    char *command = malloc(256);
	char *parameters[500];
    pid_t pid;
    int status;

    path = strcpy(path, "/bin/");  // initialize the default path of UNIX systems
    
	while (TRUE)
	{
	    pid = fork();
	    if (pid == 0)
	    {
	        printf("\n~$ ");
	        gets(command);
	        read_command(command, parameters);
	        
	        command = strcat(path, command);
	        execve(command, parameters, NULL);
	    }
	    else
	    {
	        waitpid(-1, &status, 0);
	    }		
    }

	return 0;
}

void read_command(char *command, char *parameters[])
{
    char *token;
    token = strtok(command, " ");
	int argc = 0;
	
	while(token != NULL)
	{
		char *tmp = (char*) malloc(sizeof(char)*strlen(token));
		strcpy(tmp, token);
		parameters[argc] = tmp;
		++argc;
		token = strtok(NULL, " ");
	}
	parameters[argc] = NULL;
}

