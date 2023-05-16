#include "shell.h"

/**
 * _pipe_handler - function that split given string line
 * into list of command by pipe
 *
 * @line: to be splitted
 * Return: list of command that were splitted by pipe
 */
list_t *_pipe_handler(const char *line)
{
	list_t *pipe_list;
	char **pipe_commands, **iterator;
	command_t *cmd;

	pipe_list = NULL;
	iterator = pipe_commands = _split(line, "|");
	if (!iterator)
	{
		return (NULL);
	}
	while (*iterator)
	{
		cmd = _handle_command(*iterator);
		add_to_list(&pipe_list, cmd);
		iterator++;
	}
	_free_split(&pipe_commands);
	return (pipe_list);
}

/**
 * _close_fdpipe - function that closes all fds
 * that are opened by pipe syscall
 *
 * @fd: an array contain 2 file descriptor
 * Return: nothing
 */
void _close_fdpipe(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

/**
 * _handle_pipe_execution - function executes given commands
 * that were splited by pipe
 *
 * @pipes: bunch of commands splited using pipe
 * @prev_infd: previous input file description
 * initialize with stdin(0) at first call
 * Return: 1 on success 0 on error
 */
int _handle_pipe_execution(list_t *pipes, int prev_infd)
{
	int fd[2], pid, status;
	command_t *command;

	if (!pipes)
		return (1);
	pipe(fd);
	pid = fork();
	if (pid < 0)
	{
		_close_fdpipe(fd);
		return (0);
	}
	if (!pid)
	{
		command = pipes->data;
		close(fd[0]);
		dup2(prev_infd, 0);
		if (pipes->next)
			dup2(fd[1], 1);
		execve(command->name, command->arguments, __environ);
		exit(errno);
	}
	else
	{
		close(fd[1]);
		if (prev_infd)
			close(prev_infd);
		_handle_pipe_execution(pipes->next, fd[0]);
		waitpid(pid, &status, 0);
	}
	return (1);
}
