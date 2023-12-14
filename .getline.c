#include "s_sh.h"

char *my_getline(void)
{
    static char buffer[UTTERMOST_LENGTH];/* Static buffer to store input*/
    static int position = 0; /*Position tracker in the buffer*/
    static int bytesRead = 0; /*Number of bytes read*/

    char *line = NULL;
    int currentSize = 0;
    int endOfLine = 0;
    int i, j = 0;

     while (!endOfLine) {
        /* Read from stdin only when the buffer is empty or when all characters in buffer are processed*/
        if (position >= bytesRead || position == 0) {
            position = 0;
            bytesRead = read(STDIN_FILENO, buffer, UTTERMOST_LENGTH);
            if (bytesRead == 0) {
                /*End of input reached*/
                endOfLine = 1;
                break;
            } else if (bytesRead < 0) {
                perror("Error reading from stdin");
                exit(EXIT_FAILURE);
            }
        }

        while (position < bytesRead) {
            if (buffer[position] == '\n') {
                endOfLine = 1;
                break;
            }
            position++;
            currentSize++;
        }

	if (endOfLine)
	{
        /*allocate memory for the line*/
        line = realloc(line, currentSize + 1);
        if (line == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        /*Copy characters from buffer to line*/
        
        for (i = position - currentSize; i < position; i++) {
            line[j++] = buffer[i];
        }
        line[j] = '\0';
	}
    }

    return line;
}
