#include "s_sh.h"

void process(char *command)
{
	/*char *argv[MAX_ARGS];*/
        int i = 0;

   	 /* Tokenize the input*/
    	char *token = strtok(command, " ");

	  pid_t pid;
        char *file_path;
	char *argv[MAX_ARGS];

    while (token != NULL && i < MAX_ARGS - 1) {
        argv[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    argv[i] = NULL; /*Set the last element to NULL for execve*/
	
	/*char *argv[MAX_ARGS];*/
	/*pid_t pid;
	char *file_path;*/
	
	/*int val;*/
	
	/*char *argv[] = {"/bin/ls", NULL};*/
	/*parse_command(command, args[])*/

	pid = fork();
	
	if (pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		file_path = get_path(argv[0]);	
		if (execve(file_path, argv, NULL) == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

/*void process(void)
{
	char *argv[MAX_ARGS];
	pid_t pid;
	char *full_path;

	pid = fork();
	if (pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		full_path = get_path(argv[0]);
		if (full_path != NULL)
		{
			execv(full_path, argv);
			free(full_path);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else {
			printf("Command '%s' not found\n", argv[0]);
			exit(EXIT_SUCCESS);
		}
	}
	
	else
	{
		wait(NULL);
	}
}*/
