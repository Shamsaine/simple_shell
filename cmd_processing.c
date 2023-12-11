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
		execve(full_path, argv, NULL);
		free(full_path);
		perror("Error");
		exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
