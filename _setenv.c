#include "shell.h"

/**
 * _setenv - builtins that helps
 * add new entries to our envs
 * or update entries from it
 *
 * @command: struct that stores information
 * about current running command
 * Return: (0) success otherwise error
 */
int _setenv(command_t *command)
{
	int len;

	len = _str2dlen(command->arguments + 1);
	if (len != 2)
	{
		_fprint(2, "%s: Invalid number of arguments\n",
				_global_states(GET_SHELL_NAME, NULL));
		return (1);
	}
	_enviroment_management(
		SET_ENTRY,
		command->arguments[1],
		command->arguments[2]);
	return (0);
}
