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
		return (_get_value(map, key));
	else if (action == GET_KEYS)
		return (_get_keys(map));
	else if (action == CONVERT_INTO_2D)
		return (_convert_env_into_2d_array());
	else if (action == CLEAR_ENV)
		_clear_map(map);
	return (NULL);
}
