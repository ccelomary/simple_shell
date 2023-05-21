#include "shell.h"

/**
 * _evaluate_enviroment_variable - function
 * that takes key and return it's respective
 * value
 *
 * @env_key: key to retrieve it's value from enviroment
 * variables
 * Return: corresponding value to given key
 */
char *_evaluate_enviroment_variable(char *env_key)
{
	char *value;
	int number;

	if (_strcmp(env_key, "?"))
	{
		number = _status_management(GET_STATUS, 0);
		return (_itoa(number));
	}
	if (_strcmp(env_key, "$"))
		return (_itoa(getpid()));
	value = _enviroment_management(GET_VALUE, env_key, NULL);
	return (value);
}
