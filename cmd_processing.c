#include "s_sh.h"
/*void process(void)
{
	pid_t pid;
	int val;
	
	char *argv[] = {"/bin/ls", NULL};
	pid = fork();
	
	if (pid == -1)
	{
		return;
	}
	if (pid == 0)
	{
		
		val = execve(argv[0], argv, NULL);
		if (val == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return;
}*/
void process(void)
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
}
