#ifndef S_SH_H
#define S_SH_H

#define UTTERMOST_LENGTH 100
#define MAX_ARGS 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>

extern char **environ;
ssize_t the_getline(char **storeline, size_t *bsize, FILE *stream);
void show(void);
void errorhandle(char *userinput);
void process(char *userinput);
char *pathfinder(const char *userinput);
void shellexit(void);
void printenv(void);
int mr_putchar(char a);
char *my_getline(void);
char *_strtok(char *str, const char *delim);



#endif
