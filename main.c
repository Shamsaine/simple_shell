#include "s_sh.h"
/**
 * main - this is a function
 *
 * Return: always 0
 */
int main(void)
{
	char command[UTTERMOST_LENGTH];

	while (1)
	{
		show();
		userintake(command, sizeof(command));
		process();
		errorhandle(command);
		break;
	}
	return (0);
}
