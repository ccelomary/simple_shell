#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char *_copy(char *dest, char *src, size_t size);
void *_realloc(void *old_buffer, size_t old_size, size_t new_size);
ssize_t _getline(char **line);
size_t _strlen(char *s);
void _free_split(char ***backets);
char **_split(char *line, char *diameter);
void _free_split(char ***backets);
#endif
