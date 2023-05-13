#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void *_realloc(void *old_buffer, size_t old_size, size_t new_size);
ssize_t _getline(char **line);
#endif
