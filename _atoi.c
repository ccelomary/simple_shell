#include "shell.h"

/**
 * _atoi - function that convert
 * string into integer
 *
 * @str: to be converted
 * Return: converted integer
 */
int _atoi(const char *str)
{
	int number;
	int sign;

	sign = 1;
	number = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		number = number * 10 + (*str - 48);
		str++;
	}
	return (number * sign);
}
