#include "header.h"

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("MOH & SHAMS> ");
		fgets(command, sizeof(command), stdin);

		if (command[strlen(command) - 1] == '\n')
		{
			command[strlen(command) - 1] = '\0';
		}

		if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
		{
			break;
		}

		else
		{
			system(command);
		}
	}

	printf("Shell closed.\n");
	return (0);
}
