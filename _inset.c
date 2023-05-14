#include "shell.h"

/**
 * _inset - function that looks for str in the given set
 *
 *
 * @str: str to lookup for in the given set
 * @set: sequence of different string to check against
 * @set_length: the end of the string
 * Return: 1 if the str found in set, otherwise 0 returned
 */
int _inset(char *str, char *set[], size_t set_length)
{
	int index;

	index = 0;
	while (index < set_length)
	{
		if (strcmp(str, set[index]))
			return (1);
		index++;
	}
	return (0);
}
