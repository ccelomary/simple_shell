#include "shell.h"

/**
 * find_next_newline - function that look up for newline or end of the buffer
 *
 * @buffer: buffer to look up in
 * @length: the length of the buffer
 * Return: number of read character or -1 in case of error
 */
size_t find_next_newline(char *buffer, size_t length)
{
	size_t position;

	position = 0;
	while (position < length && buffer[position] != '\n')
		position++;
	return (position);
}
/**
 * _getline - function takes address of line to fill with characters
 *
 * @line: address to line that will be filled with characters
 * Return: number of read characters in case of error return -1
 */
ssize_t _getline(char **line)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t current_position, end_of_buffer;
	ssize_t old_size, next_newline;

	*line = NULL;
	old_size = 0;
	while (1)
	{
		if (current_position >= end_of_buffer)
		{
			end_of_buffer = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			current_position = 0;
			if (end_of_buffer < 0)
			{
				free(*line);
				*line = NULL;
				return (-1);
			}
			if (end_of_buffer == 0)
				return (old_size);
		}
		next_newline = find_next_newline(buffer + current_position,
										 end_of_buffer - current_position);
		*line = _realloc(*line, old_size, old_size + next_newline);
		if (!*line)
			return (-1);
		_copy((*line) + old_size, buffer + current_position, next_newline);
		old_size += next_newline;
		current_position += next_newline;
		if (current_position < end_of_buffer)
		{
			current_position++;
			return (old_size);
		}
		current_position++;
	}
	return (-1);
}
