#include "shell.h"

/**
 * __exit - function that exit
 * from the program
 *
 * @command: struct that holds data
 * about command
 * Return: 0 success, otherwise error
 */
int __exit(command_t *command)
{
	char **iterator;
	int len;

	iterator = command->arguments + 1;
	len = _str2dlen(iterator);
	if (len > 0 && !_isdigit(*iterator))
	{
		_fprint(2, "%s: %d: exit: Illegal number: %s\n",
				_global_states(GET_SHELL_NAME, NULL),
				*((int *)_global_states(GET_LINE_NUMBER, NULL)),
				command->arguments[1]);
		return (2);
	}
	else
	{
		_enviroment_management(CLEAR_ENV, NULL, NULL);
		free(_global_states(GET_LINE, NULL));
		iterator = _global_states(GET_2D, NULL);
		_free_split(&iterator);
		if (!len)
		{
			_free_command(command);
			_exit(_status_management(GET_STATUS, 0));
		}
		len = _atoi(command->arguments[1]);
		_free_command(command);
		_exit(len);
	}
	return (0);
}
