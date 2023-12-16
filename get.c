#include "s_sh.h"
/**
 * pathfinder - this is a path function
 * @userinput: parameter
 * Return: always 0
 */
char *pathfinder(const char *userinput)
{
	char *path_environ = getenv("PATH");
	char *way = _strtok(path_environ, ":");
	char *fullypath;

	while (way != NULL)
	{
		fullypath = malloc(strlen(way) + strlen(userinput) + 2);
		if (fullypath == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		sprintf(fullypath, "%s/%s", way, userinput);
		if (access(fullypath, X_OK) == 0)
		{
			return (fullypath);
		}
		free(fullypath);
		way = _strtok(NULL, ":");
	}
	return (NULL);
}
