#include "shell.h"

/**
 * _env - builtin function that print whatever
 * inside our enviroment variables
 *
 * @command: command_t contains informations
 * about the user command
 * Return: 0 success, 1 error
 */
int _env(command_t *command)
{
	char **envs, **iterator;

	(void)command;

	iterator = envs = _enviroment_management(CONVERT_INTO_2D, NULL, NULL);
	if (!iterator)
		return (1);
	while (*iterator)
	{
		_fprint(1, "%s\n", *iterator);
		iterator++;
	}
	_free_split(&envs);
	return (0);
}
