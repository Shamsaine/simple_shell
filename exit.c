#include "s_sh.h"

/**
 * shellexit - function that exits the shell
 */

void shellexit(void)
{
	char *c = "Exiting...";

	write(1, c, strlen(c));
	mr_putchar('\n');
	exit(EXIT_SUCCESS);
}
