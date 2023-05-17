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

int main(int ac, char *av[], char **env)
{
	char *line;

	signal(SIGINT, _handle_sigint);
	_enviroment_management(INIT_ENV, NULL, NULL);
	_feed_enviroment_variable(env);
	char *path = _enviroment_management(GET_VALUE, "PATH", NULL);
	printf("%s\n", path);
	free(path);
	while (1)
	{
		prompt();
		_getline(&line);
		if (!line || _strcmp(line, "exit") || _parsing_error_handler(line))
		{
			free(line);
			break;
		}
		_semicolon_handler(line);
		printf("current Status %d\n", _status_management(GET_STATUS, 0));
		free(line);
	}
	return (0);
}
