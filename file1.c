#include "s_sh.h"
/**
 * show - this is a function to display prompt
 *
 * Return: 0
 */
void show(void)
{
	char *shellname = "MOH & SHAMS> ";

	write(1, shellname, strlen(shellname));
}

/**
 * userintake - this function takes in user input
 * @command: parameter
 * Return: always 0
 */
void userintake(char *command)
{
	/*command[UTTERMOST_LENGTH];*/

	size_t length;

	length = strlen(command);

	if (fgets(command, sizeof(command), stdin) == NULL)
	{
		printf("\n");
		/*break;*/
	}
	if (command[length - 1] == '\n')
	{
		command[length - 1] = '\0';
	}
}
