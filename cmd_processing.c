#include "s_sh.h"
void process(void)
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
		}
	}
	else
	{
		wait(NULL);
		printf("done with execve\n");
	}
	return;
}
