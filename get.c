#include "s_sh.h"

<<<<<<< HEAD
char get_path(const char command) {
    char path_env = getenv("PATH");
    char path = strtok(path_env, ":");
=======
char *get_path(const char *command)
{
	char *path_env = getenv("PATH");
    char *path = strtok(path_env, ":");
>>>>>>> 7a48ad79b7abb1937e501183c51e29495c34b801

    while (path != NULL) {
        char *full_path = malloc(strlen(path) + strlen(command) + 2);
        if (full_path == NULL) {
            perror("Error");
            exit(EXIT_FAILURE);
        }

        sprintf(full_path, "%s/%s", path, command);

        if (access(full_path, X_OK) == 0) {
            return full_path;
        }

        free(full_path);
        path = strtok(NULL, ":");
    }

    return NULL;
}
