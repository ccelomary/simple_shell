#include "shell.h"

/**
   * pop_from_list - Remove and return data from front of list.
   * @list: Ptr to ptr of head of list.
   * Return: Ptr to data removed, or NULL if list is empty.
   */
void *pop_from_list(list_t **list)
{
	list_t *removed_node = *list;
	void *removed_data = removed_node->data;

	if (!list && *list == NULL)
	{
		return (NULL);
	}

	*list = removed_node->next;
	free(removed_node);

	return (removed_data);
}
