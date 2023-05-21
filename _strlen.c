#include "shell.h"
/**
 * _strlen - function that calculate the length of given string
 *
 * @s: string (characters)
 * Return: number of characters
 */
size_t _strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}
