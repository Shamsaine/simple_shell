#include "s_sh.h"

char get_path(const charcommand) {
    char path_env = getenv("PATH");
    charpath = strtok(path_env, ":");

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
