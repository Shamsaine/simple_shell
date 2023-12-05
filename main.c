#include "s_sh.h"
/**
 * main - this is a function
 *
 * Return: always 0
 */
int main(void)
{
	char command[UTTERMOST_LENGTH];

	while (true)
	{
		show();
		userintake(command);
		errorhandle(command);

		/*if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
		{
			;
		}

		break;*/
	}
	return (0);
}
