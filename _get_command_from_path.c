#include "shell.h"

/**
 * _get_command_from_path - function that takes command
 * and return it's corresponding path
 *
 * @command: command to lookup for it's path
 * Return: path where command located
 */
char *_get_command_from_path(char *command)
{
	char *proper_command, *path,
		**path_2d, **iterator;
	struct stat st;

	if ((command[0] == '.' || command[0] == '/') &&
		!stat(command, &st))
		return (_strdup(command));
	path = _enviroment_management(GET_VALUE, "PATH", NULL);
	if (!path)
		return (_strdup(command));
	iterator = path_2d = _split(path, ":");
	free(path);
	while (*iterator)
	{
		path = _strcat(*iterator, "/");
		proper_command = _strcat(path, command);
		free(path);
		if (!stat(proper_command, &st))
		{
			_free_split(&path_2d);
			return (proper_command);
		}
		free(proper_command);
		iterator++;
	}
	_free_split(&path_2d);
	return (_strdup(command));
}
