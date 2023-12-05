#ifndef S_SH_H
#define S_SH_H

#define UTTERMOST_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

void show(void);
void userintake(char *command);
void errorhandle(char *command);

#endif
