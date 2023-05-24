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

	pid = fork();
	if (!pid)
	{
		execve(command->name, command->arguments, __environ);
		_free_command(command);
		perror(_global_states(GET_SHELL_NAME, NULL));
		_exit(errno);
	}
	else
	{
		waitpid(pid, &status, 0);
		_status_management(UPDATE_STATUS, WEXITSTATUS(status));
	}
}
