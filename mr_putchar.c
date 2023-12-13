#include "s_sh.h"
/**
 * mr_putchar - this is a function that gives output
 * @a: parameter
 * Return: any
 */
int mr_putchar(char a)
{
	return (write(1, &a, 1));
}
