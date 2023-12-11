#include "s_sh.h"
int parse_command(char *command, char *argv[]) {
    int i = 0;

    /* Tokenize the input*/
    char *token = strtok(command, " ");

    while (token != NULL && i < MAX_ARGS - 1) {
        argv[i] = token;
<<<<<<< HEAD
        i++;
        token = strtok(NULL, " ");
=======
        token = strtok(NULL, " ");
	i++;
>>>>>>> 7a48ad79b7abb1937e501183c51e29495c34b801
    }

    argv[i] = NULL; /*Set the last element to NULL for execve*/

    return i; /*Return the number of arguments*/
}
