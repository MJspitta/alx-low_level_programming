#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 *
 * Return: pointer to new hash table or NULL (failure)
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	unsigned long int i;

	table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	table->array = (hash_node_t **)malloc(size * sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		table->array[i] = NULL;

	table->size = size;

	return (table);
}
