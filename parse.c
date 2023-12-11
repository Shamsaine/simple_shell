#include "s_sh.h"
int parse_command(char *command, char *argv[]) {
    int i = 0;

    /* Tokenize the input*/
    char *token = strtok(command, " ");

    while (token != NULL && i < MAX_ARGS - 1) {
        argv[i] = token;
        token = strtok(NULL, " ");
	i++;
    }

    argv[i] = NULL; /*Set the last element to NULL for execve*/

    return i; /*Return the number of arguments*/
}
