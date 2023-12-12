#include "s_sh.h"
/**
 * get_path - this is a path function
 * @command: parameter
 * Return: always 0
 */
char *get_path(const char *command)
{
	char *path_env = getenv("PATH");
	char *path = strtok(path_env, ":");
	char *full_path;

	while (path != NULL)
	{
		full_path = malloc(strlen(path) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", path, command);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		path = strtok(NULL, ":");
	}
	return (NULL);
}
