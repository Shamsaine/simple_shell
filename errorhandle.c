#include "s_sh.h"

/**
 * errorhandle - function that handles wrong commands and errors
 *
 *
 */

void errorhandle(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *args[2];
		args[0] = command;
		args[1] = NULL;

		execve(command, args, NULL);

		perror("Error");
		exit(EXIT_FAILURE);
	}

	else if (pid > 0)
	{
		wait(NULL);
	}

	else
	{
		perror("Error");
	}
}
