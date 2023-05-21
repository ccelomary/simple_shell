#include "shell.h"

/**
 * _delete_entry - function that removes
 * entry from hashmap by given key index
 *
 * @map: map to delete entry from
 * @key: string key of the entry
 * Return: (0) success, (1) error
 */
int _delete_entry(map_t *map, const char *key)
{
	list_t *list, *tmp;
	int backet_index;
	entry_t *entry;

	backet_index = _get_hash_code(key);
	list = map->backets[backet_index];
	if (!list)
		return (0);
	entry = list->data;
	if (_strcmp(entry->key, key))
	{
		map->backets[backet_index] = list->next;
		_clear_entry(list->data);
		free(list);
		return (0);
	}
	while (list->next)
	{
		entry = list->next->data;
		if (_strcmp(entry->key, key))
		{
			tmp = list->next;
			list->next = list->next->next;
			_clear_entry(tmp->data);
			free(tmp);
			break;
		}
		list = list->next;
	}
	return (0);
}
