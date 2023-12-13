#include "s_sh.h"

void printenv(void) {
    extern char **environ;
    char **env = environ;

    printf("Current environment:\n");
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}
/**
 * printenv - function that prints environment variables
 *
 */

/*void printenv(void)
{
	extern char **environ;
	char **env = environ;
	char *d = "Current Environment:";

	write(1, d, strlen(d));
	mr_putchar('\n');

	while (*env != NULL)
	{*/
		/*printf("%s\n", *env);*/
		/*write(1, *env, strlen(*env));
		env++;
	}
}*/
