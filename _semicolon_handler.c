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
	list_t *pipes;
	int execution_ret;

	iterator = semi_commands = _split(line, ";");
	if (!iterator)
		return (1);
	while (*iterator)
	{
		pipes = _pipe_handler(*iterator);
		if (!pipes)
			return (0);
		execution_ret = _handle_pipe_execution(pipes, 0);
		free_list(pipes, _free_command);
		if (!execution_ret)
			return (1);
		iterator++;
	}
	_free_split(&semi_commands);
}
