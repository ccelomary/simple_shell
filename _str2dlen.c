#include "shell.h"

/**
 * _str2dlen - function that counts
 * the length of 2d array
 *
 * @arr2d: to count it's length
 * Return: length of given array
 */
int _str2dlen(char **arr2d)
{
	int len;

	len = 0;
	if (!arr2d)
		return (0);
	while (arr2d[len])
		len++;
	return (len);
}
