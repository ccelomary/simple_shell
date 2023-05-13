#include "shell.h"

/**
 * _realloc - function that takes buffer and increase it's size
 *
 * @old_buffer: old data of the buffer
 * @old_size: size of the buffer before update
 * @new_size: size of the buffer after
 * Return: buffer after it's being allocated, NULL in error
 */
void *_realloc(void *old_buffer, size_t old_size, size_t new_size)
{
	unsigned char *buffer;
	unsigned char *char_buffer;
	size_t iter;

	buffer = malloc(sizeof(unsigned char) * (new_size + 1));
	if (!buffer)
		return (NULL);
	char_buffer = old_buffer;
	iter = 0;
	while (char_buffer && iter < old_size)
	{
		buffer[iter] = char_buffer[iter];
		iter++;
	}

	while (iter < new_size)
	{
		buffer[iter] = 0;
		iter++;
	}
	buffer[iter] = 0;
	free(old_buffer);
	return (buffer);
}
