#include "s_sh.h"


void process(void)
{
	pid_t pid;
	int val;
	int fd[2];
	
	char *argv[] = {"/bin/ls", NULL};
	pid = fork();
	
	if (pid == -1)
	{
		return;
	}
	if (pid == 0)
	{
		pipe(fd);

		dup2(fd[1], STDOUT_FILENO);

		close(fd[0]);
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
		printf("done with execve\n");
	}
	return;
}
