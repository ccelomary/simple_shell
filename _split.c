#include "shell.h"
#include <stdio.h>

int check_diameter(char *str, char *diameter)
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

size_t backet_count(char *line, char *diameter)
{
	size_t counter, index, before, is_diameter;

	counter = 0;
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

size_t get_next_diameter(char *line, char *diameter)
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

char **_split(char *line, char *diameter)
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
