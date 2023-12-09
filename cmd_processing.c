#include "s_sh.h"

void process(char *args[]) {
    pid_t pid;
    int status;
    int fd[2];

    pipe(fd);

    pid = fork();

    if (pid == 0) {
        /* Child process */
        close(fd[0]); /* Close the read end of the pipe */
        dup2(fd[1], STDOUT_FILENO); /* Redirect stdout to the write end of the pipe*/
        close(fd[1]); /* Close the original stdout descriptor */
        execve(args[0], args, NULL);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Forking error */
        perror("Error forking");
    } else {
        /* Parent process */
        close(fd[1]); /* Close the write end of the pipe */
        waitpid(pid, &status, 0); /* Wait for the child process to finish */
        /* Read and handle output from the pipe if needed */
        close(fd[0]); /* Close the read end of the pipe */
    }
}




/*void process(void)
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
}*/
