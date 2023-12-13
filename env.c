#include "s_sh.h"

/**
 * printenv - function that prints environment variables
 *
 */

void printenv(void)
{
	char **env;
	char *d = "Current Environment:";

	write(1, d, strlen(d));
	mr_putchar('\n');

	for (env = environ; *env != NULL; env++)
	{
		/*printf("%s\n", *env);*/
		write(1, *env, strlen(*env));
	}
}

