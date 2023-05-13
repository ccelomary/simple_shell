#include "shell.h"
/**
 * _free_split - function that frees the allocted backets
 *
 * @backets: backets to free
 * Return: void
 */
void _free_split(char ***backets)
{
	char **head;

	head = *backets;
	while (*head)
	{
		free(*head);
		head++;
	}
	free(*backets);
	*backets = NULL;
}
