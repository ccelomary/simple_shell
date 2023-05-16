#include "shell.h"

/**
 * _init_map - initializes a new hash table and returns a pointer to it.
 *
 * Return: a pointer two inititialized map
 */
map_t *_init_map(void)
{
	map_t *map = (map_t *)malloc(sizeof(map_t));
	int    iterator;

	iterator = 0;
	while (iterator < BACKET_SIZE)
	{
		map->backets[iterator] = NULL;
		iterator++;
	}
	return (map);
}
