#include "s_sh.h"
/**
 * printenv - function that prints environment variables
 *
 */

void printenv(void)
{
	char **env = environ;
	char *d = "Current Environment:";

	write(1, d, strlen(d));
	mr_putchar('\n');

	while (*env != NULL)
	{
	write(1, *env, strlen(*env));
		env++;
	}
}
