#include "shell.h"

/**
 * _get_hash_code - calculates the hash code for a given key.
 *
 * @key: key to be hash
 *
 * Return: return an integer signify hashed code of the given key
 */
int _get_hash_code(const char *key)
{
	int hash = 0;
	int i;

	for (i = 0; key[i] != '\0'; i++)
	{
		hash += key[i];
	}

	return (hash % BACKET_SIZE);
}
