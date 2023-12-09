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

void show(void);
/*void userintake(char *command, size_t bufsize);*/
void errorhandle(char *command);
void process(void);
int parse_input(char *input, char *args[]);

#endif
