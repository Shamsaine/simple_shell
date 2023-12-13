#include "s_sh.h"
/**
 * get_path - this is a path function
 * @command: parameter
 * Return: always 0
 */
char *pathfinder(const char *instruct)
{
	char *path_environ = getenv("PATH");
	char *way = strtok(path_environ, ":");
	char *fullypath;

	while (way != NULL)
	{
		fullypath = malloc(strlen(way) + strlen(instruct) + 2);
		if (fullypath == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		sprintf(fullypath, "%s/%s", way, instruct);
		if (access(fullypath, X_OK) == 0)
		{
			return (fullypath);
		}
		free(fullypath);
		way = strtok(NULL, ":");
	}
	return (NULL);
}
