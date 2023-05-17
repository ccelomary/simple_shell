#include "shell.h"

/**
 *  _convert_env_into_2d_array - function that turns
 * env into array 2d
 *
 * Return: array 2d or NULL signifying error
 */
char **_convert_env_into_2d_array(void)
{
	list_t *keys, *iterator;
	size_t len_iter;
	char **array;
	char *tmp;

	iterator = keys = _enviroment_management(GET_KEYS, NULL, NULL);
	len_iter = _listlen(keys);
	array = malloc(sizeof(char *) * (len_iter + 1));
	if (!array)
	{
		free_list(keys, free);
		return (NULL);
	}
	array[len_iter] = NULL;
	len_iter = 0;
	while (iterator)
	{
		tmp = _strcat(iterator->data, "=");
		array[len_iter] = _strcat(tmp,
								  _enviroment_management(GET_VALUE,
														 iterator->data,
														 NULL));
		free(tmp);
		iterator = iterator->next;
		len_iter++;
	}
	free_list(keys, free);
	return (array);
}

/**
 * _feed_enviroment_variable - function take whatever
 * is inside given 2d enviroment and split by space
 * and add it to the global env
 *
 * @new_env: enviroment as 2d array
 * Return: void;
 */
void _feed_enviroment_variable(char **new_env)
{
	char **entry;

	while (*new_env)
	{
		entry = _split(*new_env, "=");
		_enviroment_management(SET_ENTRY, entry[0], entry[1]);
		_free_split(&entry);
		new_env++;
	}
}
