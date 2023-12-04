#include "s_sh.h"
/**
 * show - this is a function to display prompt
 *
 * Return: 0
 */
void show()
{
	char *shellname = "MOH & SHAMS> ";

	write(1, shellname, strlen(shellname));
}

/**
 * userintake - this function takes in user input
 *
 * Return: always 0
 */
void userintake()
{
	char *command;

	fgets(command, sizeof(command), stdin);
}
