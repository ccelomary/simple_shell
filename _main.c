#include "shell.h"

/**
 * main - entry level function
 *
 * @ac: number of passed arguments
 * @av: arguments
 * Return: 0 sucess, otherwise error
 */
int main(int ac, char *av[])
{
	char *line, *no_comment_line;

	(void)ac;
	signal(SIGINT, _handle_sigint);
	_enviroment_management(INIT_ENV, NULL, NULL);
	_feed_enviroment_variable(__environ);
	_builtin_management(SET_BUILTIN, "exit", __exit);
	_builtin_management(SET_BUILTIN, "env", _env);
	_builtin_management(SET_BUILTIN, "setenv", _setenv);
	_builtin_management(SET_BUILTIN, "unsetenv", _unsetenv);
	_builtin_management(SET_BUILTIN, "cd", _cd);
	_global_states(SET_SHELL_NAME, &av[0]);
	while (1)
	{
		_prompt();
		_getline(&line);
		if (!line)
		{
			free(line);
			break;
		}
		no_comment_line = _trim_white_space(line);
		free(line);
		line = no_comment_line;
		no_comment_line = _exclude_comment(line);
		free(line);
		line = no_comment_line;
		_global_states(SET_LINE, &line);
		_global_states(INCREMENT_LINE_NUMBER, NULL);
		_semicolon_handler(line);
		free(line);
	}
	_enviroment_management(CLEAR_ENV, NULL, NULL);
	return (_status_management(GET_STATUS, 0));
}
