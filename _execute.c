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
	char **envs;

	pid = fork();
	if (!pid)
	{
		envs = _enviroment_management(CONVERT_INTO_2D, NULL, NULL);
		execve(command->name, command->arguments, envs);
		_free_command(command);
		_free_split(&envs);
		perror(_global_states(GET_SHELL_NAME, NULL));
		exit(errno);
	}
	else
	{
		waitpid(pid, &status, 0);
		_status_management(UPDATE_STATUS, WEXITSTATUS(status));
	}
}
