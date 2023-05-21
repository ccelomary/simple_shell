#include "shell.h"

/**
 * _strslice - function that  take string
 * and return specified part of it
 *
 * @line: to be sliced
 * @start: start position index zero based
 * @end: end position index zero based(excluded)
 * Return: part of the string
 */
char *_strslice(const char *line, int start, int end)
{
	char *slice;
	int len, iter;

	if (start < 0)
		start = 0;
	len = _strlen(line);
	if (len < end || end < 0)
		end = len;
	slice = malloc(sizeof(char) * (end - start + 1));
	iter = 0;
	while (start + iter < end)
	{
		slice[iter] = line[start + iter];
		iter++;
	}
	slice[iter] = 0;
	return (slice);
}
