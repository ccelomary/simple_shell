#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define BACKET_SIZE 64

/**
 *struct entry_s - struct that hold key and value
 * of hash table
 *
 *@key: the key used to retrieve values
 *@value: the respective data for the key
 */
typedef struct entry_s
{
	char *key;
	char *value;
} entry_t;


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
 * struct map_s - defines a structure for a hash table
 *
 * @backets: an array of linkedlist where
 * our entry data will be stored
 */
typedef struct map_s
{
	list_t  *backets[BACKET_SIZE];
}  map_t;

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
char   *_strdup(const char *str);
int _get_hash_code(const char *key);
map_t *_init_map(void);
int    _set_value(map_t  *map, const char *key, const char *value);
char  *_get_value(const map_t *map, const char *key);
void    _clear_entry(void *data);
void    _clear_map(map_t *map);
list_t    *_get_keys(const map_t *map);
#endif
