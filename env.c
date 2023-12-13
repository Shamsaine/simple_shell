#include "s_sh.h"

/**
 * printenv - function that prints environment variables
 *
 */

void printenv(void)
{
	char **env;

	printf("Current Environment:\n");

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

