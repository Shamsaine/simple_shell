#include "s_sh.h"

char *my_getline(void) {
    static char buffer[UTTERMOST_LENGTH];
    int bytesRead;
    char *line;

    if ((bytesRead = read(STDIN_FILENO, buffer, UTTERMOST_LENGTH)) == -1) {
        perror("Error reading from stdin");
        exit(EXIT_FAILURE);
    }

    if (bytesRead == 0) {
        
        return NULL;
    }

    buffer[bytesRead] = '\0';

    
    line = malloc(bytesRead + 1);
    if (line == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    
    strcpy(line, buffer);

    return line;
}
