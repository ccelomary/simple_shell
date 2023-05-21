#include "shell.h"

/**
 * _isdigit - function that takes a
 * string and check wether it's digit or
 * not
 *
 * @s: string to check against
 * Return: 1 signify digits, 0 else
 */
int _isdigit(const char *s)
{
	if (!s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
