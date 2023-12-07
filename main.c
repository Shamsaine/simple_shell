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
		process();
		errorhandle(command);
	}
	return (0);
}
