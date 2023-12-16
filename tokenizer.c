#include "s_sh.h"
/**
 * _strtok - tokenizer
 *
 * @str: string to be tokenized
 * @delim: seperation identifier
 *
 * Return: token
 */

char *_strtok(char *str, const char *delim)
{
	static char *curr;
	char *token;

	if (str != NULL)
	{
		curr = str;
	}
	if (curr == NULL)
	{
		return (NULL);
	}
	while (*curr && strchr(delim, *curr))
	{
		curr++;
	}
	if (*curr == '\0')
	{
		return (NULL);
	}

	token = curr;
	while (*curr && !strchr(delim, *curr))
	{
		curr++;
	}
	if (*curr != '\0')
	{
		*curr = '\0';
		curr++;
	}
	return (token);
}
