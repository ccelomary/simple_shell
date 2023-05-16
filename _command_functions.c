#include "shell.h"

/**
 * _free_command - function that frees command
 *
 * @data: data to be freed
 * Return: Nothing
 */
void _free_command(void *data)
{
	command_t *cmd;

	cmd = data;
	_free_split(&cmd->arguments);
	free(data);
}

/**
 * _init_command - function that initialize our
 * command
 *
 * @tokens: 2d array holds all command arguments
 * and it contain command name in the first argument
 * Return: allocated command
 */
command_t *_init_command(char **tokens)
{
	command_t *command;

	command = malloc(sizeof(command_t));
	if (!command)
		return (NULL);
	command->arguments = tokens;
	command->name = tokens[0];
	return (command);
}

/**
 * _handle_command - function that takes line
 * and turn into an easy command to work with
 *
 * @line: to be parsed
 * Return: well strucered method
 */
command_t *_handle_command(const char *line)
{
	command_t *command;
	char *trimmed_line;
	char **tokens;

	trimmed_line = _trim_white_space(line);
	tokens = _split(trimmed_line, " ");
	free(trimmed_line);
	if (!tokens)
		return (NULL);
	command = _init_command(tokens);
	return (command);
}
