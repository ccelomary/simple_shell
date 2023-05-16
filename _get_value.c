#include "shell.h"

/**
 * _get_value - retrieves the value associated
 * with the given key from the hash table.
 *
 *@map: map to get the value from
 *@key: key to retieve the associated value
 * Return: pointer to the value or NULL in error
 */
char  *_get_value(const map_t *map, const char *key)
{
	int    backet_index;
	list_t  *backet;
	entry_t  *entry;

	backet_index = _get_hash_code(key);
	backet = map->backets[backet_index];
	while (backet)
	{
		entry = backet->data;
		if (_strcmp(entry->key, key))
			return (entry->value);
		backet = backet->next;
	}
	return (NULL);
}
