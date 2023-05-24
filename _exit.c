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
	_enviroment_management(CLEAR_ENV, NULL, NULL);
	free(_global_states(GET_LINE, NULL));
	_free_command(command);
	_exit(0);
	return (0);
}
