#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define UTTERMOST_LENGTH 64

ssize_t the_getline(char **storeline, size_t *bsize, FILE *stream)
{
	size_t pos;
	int c;

    if (storeline == NULL || bsize == NULL) /*if either is null*/
    {
        errno = EINVAL;
        return -1;
    }

    if (*storeline == NULL || *bsize == 0)
    {
        /*Allocate initial buffer if not already allocated*/
        *bsize = UTTERMOST_LENGTH;
        *storeline = malloc(*bsize);
        if (*storeline == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }

    /*size_t pos = 0;*/
    /*int c;*/

    while ((c = fgetc(stream)) != EOF) {
        if (pos + 1 >= *bsize) {
            /*Resize buffer if needed*/
            *bsize *= 2;
            *storeline = realloc(*storeline, *bsize);
            if (*storeline == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        (*storeline)[pos++] = (char)c;

        if (c == '\n') {
            break;
        }
    }

    if (pos > 0) {
        (*storeline)[pos] = '\0';  /* Null-terminate the line*/
        return pos;
    } else {
        /*No characters were read*/
        return -1;
    }
    return 0;
}

/*int main() {
    char *line = NULL;
    size_t len = 0;

    printf("Enter text (Ctrl+D to end):\n");

    while (the_getline(&line, &len, stdin) != -1) {
        printf("Read: %s", line);
    }

    free(line);

    return 0;
}*/
