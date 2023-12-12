#include "s_sh.h"
/**
 * process - this is a function
 * @command: parameter
 * Return: alaways 0
 */

void process(char *command)
{
	int i = 0;
	char *token = strtok(command, " ");
	pid_t pid;
	char *file_path;
	char *argv[MAX_ARGS];

	while (token != NULL && i < MAX_ARGS - 1)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
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
		else
		{
			wait(NULL);
		}
	}
}
