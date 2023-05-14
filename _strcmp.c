#include "shell.h"

/**
 * _strcmp - function checks  wether given strings
 * are identical or not
 *
 * @str1: first string to check against
 * @str2: second string to check against
 *
 * Return: 1 success case, 0 error case
 */
int _strcmp(const char *str1, const char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (!*str1 && !*str2)
		return (1);
	return (0);
}
