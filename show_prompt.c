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
