#include "shell.h"

/**
 * _excute - function that excute commands
 * that's not part of builtins
 *
 * @command: command to be executed
 * Return: Nothing(void)
 */
void _excute(command_t *command)
{
	int pid, status;
	char **s;

	pid = fork();
	if (!pid)
	{
		execve(command->name, command->arguments, __environ);
		_free_command(command);
		s = _global_states(GET_2D, NULL);
		_free_split(&s);
		free(_global_states(GET_LINE, NULL));
		perror(_global_states(GET_SHELL_NAME, NULL));
		_enviroment_management(CLEAR_ENV, NULL, NULL);
		if (errno == EACCES)
			_exit(126);
		_exit(errno);
	}
	else
	{
		waitpid(pid, &status, 0);
		_status_management(UPDATE_STATUS, WEXITSTATUS(status));
	}
}
