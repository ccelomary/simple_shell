#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

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
 * enum status_actions_e - actions that will be applied to
 * status state management
 *
 * @UPDATE_STATUS: action to update status code
 * @GET_STATUS: action to retrieve status code
 */
typedef enum status_actions_e
{
	UPDATE_STATUS,
	GET_STATUS,
} status_actions_t;

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
 *
 */
typedef struct command_s
{
	char *name;
	char **arguments;
} command_t;

/**
 * struct map_s - defines a structure for a hash table
 *
 * @backets: an array of linkedlist where
 * our entry data will be stored
 */
typedef struct map_s
{
	list_t *backets[BACKET_SIZE];
} map_t;

/**
 * enum enviroment_action_e - actions that will be applied to
 * global enviroment
 *
 * @INIT_ENV: TO INITIALIZE ENVIROMENT VARIABLE
 * @SET_ENTRY: TO ADD NEW ENTRY TO ENVIROMENT VARIABLE
 * @GET_VALUE: TO RETRIEVE VALUE FROM ENVIROMENT VARIABLE
 * @GET_KEYS: TO GET ALL KEY THAT STORED INSIDE ENV VARIABLE
 * @CONVERT_INTO_2D: RETURNS 2D ARRAY CONTAINING ALL ENVIRONEMENT
 * VARIBALES (env)
 * @CLEAR_ENV: TO FREE AND CLEAR EVERYTHING INSIDE OF OUR
 * ENV
 */
typedef enum enviroment_action_e
{
	INIT_ENV,
	SET_ENTRY,
	GET_VALUE,
	GET_KEYS,
	CONVERT_INTO_2D,
	CLEAR_ENV,
} enviroment_action_t;

char *_copy(char *dest, const char *src, size_t size);
void *_realloc(void *old_buffer, size_t old_size, size_t new_size);
ssize_t _getline(char **line);
char *_trim_white_space(const char *line);
int _parsing_error_handler(char *line);
size_t _strlen(const char *s);
void _free_split(char ***backets);
char **_split(const char *line, const char *diameter);
list_t *add_to_list(list_t **lst, void *data);
void *pop_from_list(list_t **list);
size_t _listlen(const list_t *list);
void free_list(list_t *list, void (*free_content)(void *data));
int _strcmp(const char *str1, const char *str2);
int _inset(char *str, char *set[], size_t set_length);
char *_strdup(const char *str);
int _get_hash_code(const char *key);
map_t *_init_map(void);
int _set_value(map_t *map, const char *key, const char *value);
char *_get_value(const map_t *map, const char *key);
void _clear_entry(void *data);
void _clear_map(map_t *map);
list_t *_get_keys(const map_t *map);
command_t *_init_command(char **tokens);
void _free_command(void *data);
command_t *_handle_command(const char *line);
int _semicolon_handler(const char *line);
list_t *_pipe_handler(const char *line);
int _handle_pipe_execution(list_t *pipes, int previous_stdin);
int _status_management(status_actions_t action, int new_status);
void _handle_sigint(int sig);
void *_enviroment_management(enviroment_action_t action,
							 const char *key, const char *value);
int _status_management(status_actions_t action, int new_status);
char **_convert_env_into_2d_array(void);
void _feed_enviroment_variable(char **new_env);
char *_strslice(char *line, int start, int end);
char *_strcat(const char *str1, const char *str2);
char *_itoa(int number);
#endif
