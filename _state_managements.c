#include "shell.h"

/**
 * _status_management - status state management is function that
 * allows to access and apply actions to our status globaly
 * from any function
 *
 * @action: action that will be applied to our state
 * @new_status: used when updating status
 * Return: current status
 */

int _status_management(status_actions_t action, int new_status)
{
	static int status;

	if (action == UPDATE_STATUS)
		status = new_status;
	return (status);
}

/**
 * _enviroment_management - function that allows to access
 * our global variables anywhere in our program
 * and provides us with bunch of action to be applied to our
 * map
 *
 * @action: action that will be applied to our env
 * @key: string used when adding new entry or when
 * retrieving data
 * @value: string used when adding new entry
 * Return: different types based on the given action
 */
void *_enviroment_management(enviroment_action_t action,
							 const char *key, const char *value)
{
	static map_t *map;

	if (action == INIT_ENV)
		map = _init_map();
	else if (action == SET_ENTRY)
		_set_value(map, key, value);
	else if (action == GET_VALUE)
		return (_strdup(_get_value(map, key)));
	else if (action == GET_KEYS)
		return (_get_keys(map));
	else if (action == CONVERT_INTO_2D)
		return (_convert_env_into_2d_array());
	else if (action == CLEAR_ENV)
		_clear_map(map);
	else if (action == DELETE_ENTRY)
		_delete_entry(map, key);
	return (NULL);
}

/**
 * _builtin_management - function that manages
 * builtins inside our application
 *
 * @action: action that will be applied to our
 * builtins state managements
 * @name: name of the builtin
 * @function: builtin function that will be
 * executed later
 * Return: (void *) function that associated to
 * builtin or NULL
 */
builtins_t _builtin_management(builtin_actions_t action, char *name,
							   int (*function)(command_t *command))
{
	static builtin_t builtins[10];
	static int size;
	int iter;

	if (action == GET_BUILTIN)
	{
		iter = 0;
		while (iter < size)
		{
			if (_strcmp(builtins[iter].name, name))
				return (builtins[iter].function);
			iter++;
		}
	}
	if (action == SET_BUILTIN)
	{
		_copy(builtins[size].name, name, _strlen(name));
		builtins[size].function = function;
		size++;
	}
	return (NULL);
}

/**
 * _global_states - state management that holds
 * some variables that will be used in different
 * places of the applications
 *
 * @action: actions that will be applied to
 * the globals state managements
 * @s: string to update string
 * Return: (void *)
 */
void *_global_states(globals_action_t action, char **s)
{
	static char *line, *shell_name, **array_2d;
	static int line_number;

	if (action == SET_LINE)
		line = *s;
	if (action == SET_SHELL_NAME)
		shell_name = *s;
	if (action == GET_LINE)
		return (line);
	if (action == GET_SHELL_NAME)
		return (shell_name);
	if (action == GET_LINE_NUMBER)
		return (&line_number);
	if (action == INCREMENT_LINE_NUMBER)
		line_number++;
	if (action == SET_2D)
		array_2d = s;
	if (action == GET_2D)
		return (array_2d);
	return (NULL);
}
