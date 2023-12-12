#include "s_sh.h"


void printEnvironment()
{
	extern char **environ;
	char **env;

	printf("Current Environment:\n");
	
	/*char **env;*/

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

