#include "s_sh.h"
/**
 * process - this is a function
 * @userinput: parameter
 * Return: alaways 0
 */

void process(char *userinput)
{
	int i = 0;
	char *symbol = _strtok(userinput, " ");
	pid_t proc;
	char *file_path;
	char *argv[MAX_ARGS];

	while (symbol != NULL && i < MAX_ARGS - 1)
	{
		argv[i] = symbol;
		symbol = _strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	proc = fork();
	if (proc == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	if (proc == 0)
	{
		file_path = pathfinder(argv[0]);
		if (execve(file_path, argv, NULL) == -1)
		{
			perror("error");
			free(file_path);
			exit(EXIT_FAILURE);
		}
		else
		{
			execve(file_path, argv, NULL);
		}
	}
	else
	{
		wait(NULL);
	}
}
