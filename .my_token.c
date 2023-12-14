#include "s_sh.h"
char *my_strtok(char *str, const char *delim) {
    static char *lastToken = NULL;
    char *tokenStart;

    if (str != NULL) {
        lastToken = str;
    } else if (lastToken == NULL) {

        return NULL;
    }

    while (*lastToken != '\0' && strchr(delim, *lastToken) != NULL) {
        lastToken++;
    }


    if (*lastToken == '\0') {
        lastToken = NULL;
        return NULL;
    }

    tokenStart = lastToken;
    while (*lastToken != '\0' && strchr(delim, *lastToken) == NULL) {
        lastToken++;
    }
    *lastToken = '\0';

    return tokenStart;
}
