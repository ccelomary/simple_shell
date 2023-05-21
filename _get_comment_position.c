#include "shell.h"

/**
 * _get_comment_position - function that returns the
 * position of the # or the length of the line
 * if # not found
 *
 * @line: string to lookup in
 * Return: (integer) position of the #
 * or the length if not found
 */
int _get_comment_position(const char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '#')
		{
			return (i);
		}
	}
	return (i);
}
