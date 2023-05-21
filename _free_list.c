#include "shell.h"

/**
 * free_list - Free memory allocated for the list.
 * @list: Ptr to head of list.
 * @free_content: Ptr to function for freeing node content.
 * Return: void
 */
void free_list(list_t *list, void (*free_content)(void *data))
{
	list_t *current = list;
	list_t *next;

	while (current != NULL)
	{
		next = current->next;
		if (free_content != NULL)
		{
			free_content(current->data);
		}
		free(current);
		current = next;
	}
}
