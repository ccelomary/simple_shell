#include "shell.h"

/**
 * _strcat  - function that takes 2 string and
 * combines them
 *
 * @str1: first string
 * @str2: second string
 * Return: the combination of first and second string
 * NULL on error case
 */
char *_strcat(const char *str1, const char *str2)
{
	size_t len1, len2, iter;
	char *newstr;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	newstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (NULL);
	iter = 0;
	while (iter < len1)
	{
		newstr[iter] = str1[iter];
		iter++;
	}
	while (iter - len1 < len2)
	{
		newstr[iter] = str2[iter - len1];
		iter++;
	}
	newstr[iter] = 0;
	return (newstr);
}
