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
	int pid, status, err;

	pid = fork();
	if (pid < 0)
	{
		perror((char *)_global_states(GET_SHELL_NAME, NULL));
		_status_management(UPDATE_STATUS, 1);
		return;
	}
	if (!pid)
	{
		execve(command->name, command->arguments, __environ);
		err = errno;
		if (errno == EACCES)
		{
			_fprint(2, "%s: %d: %s: Permission denied\n",
					(char *)_global_states(GET_SHELL_NAME, NULL),
					*((int *)_global_states(GET_LINE_NUMBER, NULL)),
					command->name);
			err = 126;
		}
		else
			perror(_global_states(GET_SHELL_NAME, NULL));
		_free_command(command);
		free(_global_states(GET_LINE, NULL));
		_enviroment_management(CLEAR_ENV, NULL, NULL);
		_exit(err);
	}
	else
	{
		waitpid(pid, &status, 0);
		_status_management(UPDATE_STATUS, WEXITSTATUS(status));
	}
}
