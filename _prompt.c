#include "shell.h"

/**
 * _prompt - function that asks
 * a user to enter a command
 *
 * Return: Nothing (void)
 */
void _prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_fprint(1, "%s> ",
				_global_states(GET_SHELL_NAME, NULL));
	}
}
