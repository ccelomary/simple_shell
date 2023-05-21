#include "shell.h"

/**
 * check_diameter - functions that look up for next diameter
 *
 * @str: string
 * @diameter: diameter that will be used when splitting
 * Return: 0 if the str doesn't contain diameter, 1 when diameter found
 * 2 when diameter found in but followed by last character of the diameter
 */
int check_diameter(const char *str, const char *diameter)
{
	size_t iter;

	iter = 0;
	while (str[iter] && diameter[iter] && str[iter] == diameter[iter])
		iter++;
	if (diameter[iter])
		return (0);
	if (str[iter] == diameter[iter - 1])
		return (2);
	return (1);
}

/**
 * backet_count - function calculate number of
 * backets that is splited by diameter
 *
 * @line: buffer to look up in
 * @diameter: buffer to look up for
 * Return:  number of backets
 */
size_t backet_count(const char *line, const char *diameter)
{
	size_t counter, index, before, is_diameter;

	counter = 0;
	index = 0;
	before = 0;
	if (!*line)
		return (0);
	while (line[index])
	{
		is_diameter = check_diameter(line + index, diameter);
		if (is_diameter)
		{
			if (is_diameter == 2)
			{
				index++;
				before = 1;
			}
			else if (is_diameter == 1 && before)
			{
				before = 0;
				index++;
			}
			else
			{
				counter++;
				index += _strlen(diameter);
			}
		}
		else
			index++;
	}
	return (counter + 1);
}

/**
 * get_next_diameter - function return the start of
 * the next occurance of  diameter
 *
 * @line: buffer to look up in
 * @diameter: buffer to look up for
 * Return: position of the next occurance of the diameter
 */
size_t get_next_diameter(const char *line, const char *diameter)
{
	size_t index, before, is_diameter;

	index = 0;
	before = 0;
	while (line[index])
	{
		is_diameter = check_diameter(line + index, diameter);
		if (is_diameter)
		{
			if (is_diameter == 2)
			{
				index++;
				before = 1;
			}
			else if (is_diameter == 1 && before)
			{
				before = 0;
				index++;
			}
			else
				return (index);
		}
		else
			index++;
	}
	return (index);
}

/**
 * free_backets - function that frees backets
 * in case of error
 *
 * @backets: 2d array that will be freed
 * @current_position: refer to the last index before
 * error occurs
 * Return: void
 */
void free_backets(char **backets, size_t current_position)
{
	size_t index;

	index = 0;
	while (index < current_position)
	{
		free(backets[index]);
		index++;
	}
	free(backets);
}
/**
 * _split - function that splits given line by
 * given diameter
 *
 * @line: buffer to be splitted
 * @diameter: to split with
 * Return: 2d array that ends with NULL
 * or NULL in case of error
 */
char **_split(const char *line, const char *diameter)
{
	char **backets;
	size_t backet_length, current_line_position, backet_index;
	size_t next_diameter;

	backet_length = backet_count(line, diameter);
	backets = malloc(sizeof(char *) * (backet_length + 1));
	if (!backets)
		return (NULL);
	current_line_position = 0;
	backet_index = 0;
	while (backet_index < backet_length)
	{
		next_diameter = get_next_diameter(line + current_line_position, diameter);
		backets[backet_index] = malloc(sizeof(char) * (next_diameter + 1));
		if (!backets[backet_index])
		{
			free_backets(backets, backet_index);
			return (NULL);
		}
		_copy(backets[backet_index], line + current_line_position, next_diameter);
		backet_index++;
		current_line_position += next_diameter + _strlen(diameter);
	}
	backets[backet_length] = NULL;
	return (backets);
}
