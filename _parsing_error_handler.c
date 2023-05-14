#include "shell.h"

/**
 * _check_invalid_characters_occurance - function that check
 * given line against invalid characters
 *
 * @line: to lookup for invalid characters
 * Return: 1 if  invalid character found otherwise 0
 */
int _check_invalid_characters_occurance(char *line)
{
	size_t index, iter, iter2;
	char *invalid_characters[] = {
		";;",
		"|||",
		">>>",
		"<<"};

	index = 0;
	while (index < 4)
	{
		iter = 0;
		iter2 = 0;
		while (line[iter2] && invalid_characters[index][iter] &&
			   (invalid_characters[index][iter] == line[iter2] || line[iter2] == ' '))
		{
			if (line[iter2] == ' ')
				iter2++;
			else
			{
				iter2++;
				iter++;
			}
		}
		if (!invalid_characters[index][iter])
			return (1);
		index++;
	}
	return (0);
}

/**
 * _parsing_error_handler - function that takes line
 * and run it against some parsing errors
 *
 * @line: to check against
 * Return: number greater than zero error case or zero if no error occured
 */
int _parsing_error_handler(char *line)
{
	size_t len;

	if (!line || !*line)
		return (0);
	len = _strlen(line);
	if (line[0] == ';' || line[0] == '|' ||
		line[len - 1] == '|' ||
		line[len - 1] == '>' || line[len - 1] == '<')
		return (2);
	len = 0;
	while (line[len])
	{
		if (_check_invalid_characters_occurance(line + len))
			return (2);
		len++;
	}
	return (0);
}
