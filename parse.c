#include "s_sh.h"
int parse_input(char *input, char *argv[]) {
    int i = 0;

    /* Tokenize the input*/
    char *token = strtok(input, " \t\n");

    while (token != NULL && i < MAX_ARGS - 1) {
        argv[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }

    argv[i] = NULL; /*Set the last element to NULL for execve*/

    return i; /*Return the number of arguments*/
}
