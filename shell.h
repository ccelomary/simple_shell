#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * struct list_s - node of linkedlist
 *
 * @data: linkedlist content
 * @next: next node
 */
typedef struct list_s
{
	void *data;
	struct list_s *next;
} list_t;
/**
 * struct command_s - struct that holds informations
 * about command
 *
 * @name: name of the command
 * @arguments: command arguments
 * @files: command files
 *
 */
typedef struct command_s
{
	char *name;
	char **arguments;
} command_t;

char *_copy(char *dest, char *src, size_t size);
void *_realloc(void *old_buffer, size_t old_size, size_t new_size);
ssize_t _getline(char **line);
char *_trim_white_space(char *line);
int _parsing_error_handler(char *line);
size_t _strlen(char *s);
void _free_split(char ***backets);
char **_split(char *line, char *diameter);
void _free_split(char ***backets);
list_t *add_to_list(list_t **lst, void *data);
void *pop_from_list(list_t **list);
void free_list(list_t *list, void (*free_content)(void *data));
int _strcmp(const char *str1, const char *str2);
int _inset(char *str, char *set[], size_t set_length);
#endif
