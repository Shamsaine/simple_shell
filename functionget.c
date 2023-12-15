#include "s_sh.h"
/**
 * the_getline - function that processes user input
 *
 * @storeline: userinput
 * @bsize: length
 * @stream: source
 *
 * Return: success always
 */

ssize_t the_getline(char **storeline, size_t *bsize, FILE *stream)
{
	size_t xx = 0;
	int y;

	if (storeline == NULL || bsize == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (*storeline == NULL || *bsize == 0)
	{
		*bsize = UTTERMOST_LENGTH;
		*storeline = malloc(*bsize);
		if (*storeline == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
	}
	while ((y = fgetc(stream)) != EOF)
	{
		if (xx + 1 >= *bsize)
		{
			*bsize *= 2;
			*storeline = realloc(*storeline, *bsize);
			if (*storeline == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		(*storeline)[xx++] = (char)y;
		if (y == '\n')
			break;
	}
	if (xx > 0)
	{
		(*storeline)[xx] = '\0';
		return (xx);
	}
	return (-1);
}
