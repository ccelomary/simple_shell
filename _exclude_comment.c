#include "shell.h"

/**
 * _exclude_comment - remove comment from
 * line
 *
 * @line: full line that user entered
 * Return: new_line without comment
 */
char *_exclude_comment(const char *line)
{
	int comment_position;

	comment_position = _get_comment_position(line);
	return (_strslice(line, 0, comment_position));
}
