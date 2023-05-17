#include "shell.h"

/**
 * _listlen - function that calculate the
 * length of the given linkedlist
 *
 * @list: to calculate it's length
 * Return: length of list
 */
size_t _listlen(const list_t *list)
{
	size_t len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}
