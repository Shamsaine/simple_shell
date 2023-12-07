#include "s_sh.h"

void read_input(int fd[2])
{
	char buffer[1024];
        ssize_t n;
	

        while ((n = read(fd[0], buffer, sizeof(buffer))) > 0)
	{
            write(STDOUT_FILENO, buffer, n);
        }
        close(fd[0]);

        printf("done with execve\n");
}
