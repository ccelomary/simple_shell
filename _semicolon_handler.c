#include "shell.h"

/**
 * _semicolon_handler - function that splits given
 * line bu semicolon and pass the result to be
 * handled by other functions
 *
 * @line: command line to be parsed and executed
 * Return: 1 on success or 0 signifying error
 */
int _semicolon_handler(const char *line)
{
	char **semi_commands, **iterator;
	command_t *command;
	int argument_length;

	iterator = semi_commands = _split(line, ";");
	if (!iterator)
		return (1);
	while (*iterator)
	{
		command = _handle_command(*iterator);
		if (command->type == NOT_FOUND)
		{
			_fprint(2, "%s: %d: %s: not found\n",
					(char *)_global_states(GET_SHELL_NAME, NULL),
					*((int *)_global_states(GET_LINE_NUMBER, NULL)),
					command->name);
			_status_management(UPDATE_STATUS, 127);
		}
		else if (command->type == EXTERNAL)
			_excute(command);
		else
		{
			_global_states(SET_2D, semi_commands);
			_status_management(UPDATE_STATUS,
							   _builtin_management(
								   GET_BUILTIN,
								   command->name, NULL)(command));
		}
		argument_length = _str2dlen(command->arguments);
		_enviroment_management(SET_ENTRY, "_",
							   command->arguments[argument_length - 1]);
		_free_command(command);
		iterator++;
	}
	_free_split(&semi_commands);
	return (0);
}
