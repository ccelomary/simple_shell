#include "shell.h"

void _handle_sigint(int sig)
{
	(void)sig;
	fflush(stdin);
	write(1, "\n$> ", 4);
}

void prompt()
{
	write(1, "$> ", 3);
}

int main(void)
{
	char *line;

	signal(SIGINT, _handle_sigint);
	while (1)
	{
		prompt();
		_getline(&line);
		if (!line || _strcmp(line, "exit") || _parsing_error_handler(line))
		{
			free(line);
			return (1);
		}
		_semicolon_handler(line);
		free(line);
	}
	return (0);
}
