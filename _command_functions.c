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
 * _lookup_for_command - function that search
 * for given command on the builtins
 * as well as in the path
 *
 * @command: to lookup for
 * @type: the type of the command
 * Return: proper path or command if it's builtin
 */
char *_lookup_for_command(char *command, command_type_t *type)
{

	if (_builtin_management(GET_BUILTIN, command, NULL))
	{
		*type = BUILTINS;
		return (_strdup(command));
	}

	return (_get_command_from_path(command));
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
	struct stat st;
	char *scommand;

	command = malloc(sizeof(command_t));
	if (!command)
		return (NULL);
	command->type = NOT_FOUND;
	scommand = _lookup_for_command(tokens[0], &command->type);
	free(tokens[0]);
	tokens[0] = scommand;
	if (command->type == NOT_FOUND &&
		(tokens[0][0] == '.' || tokens[0][0] == '/') &&
		!stat(tokens[0], &st))
		command->type = EXTERNAL;
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
	char *trimmed_line, *command_name;
	char **tokens[2];
	int iterator;

	trimmed_line = _trim_white_space(line);
	tokens[0] = _split(trimmed_line, " ");
	free(trimmed_line);
	if (!tokens[0])
		return (NULL);
	iterator = 0;
	while (tokens[0][iterator])
	{
		if (tokens[0][iterator][0] == '$')
		{
			command_name = _evaluate_enviroment_variable(tokens[0][iterator] + 1);
			free(tokens[0][iterator]);
			if (command_name)
				tokens[0][iterator] = command_name;
			else
				tokens[0][iterator] = _strdup("");
		}
		iterator++;
	}
	tokens[1] = _trim_2darray(tokens[0]);
	_free_split(&tokens[0]);
	return (_init_command(tokens[1]));
}
