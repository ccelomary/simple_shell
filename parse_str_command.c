#include "shell.h"

redirection_t get_proper_redirect(char *sredirect)
{
	if (_strcmp(sredirect, ">"))
		return (WRITE);
	if (_strcmp(sredirect, ">>"))
		return (APPEND);
	if (_strcmp(sredirect, "<"))
		return (READ);
	return (UNDEFINED);
}

command_t *parse_str_command(char **tokens)
{
	int is_redirect, is_command;
	command_t *command;

	char *set[] = {
		">",
		">>",
		"<"};

	is_redirect = 0;
	is_command = 0;
	while (*tokens)
	{
		if (_inset(*tokens, set, 3))
		{
			is_redirect = 1;
		}
		else
		{
			if (is_redirect)
			{
			}
			else
			{
			}
			is_redirect = 0;
		}

		tokens++;
	}
}
