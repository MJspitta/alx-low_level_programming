#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int first;
	hash_node_t *curr;

	if (ht == NULL)
		return;

	printf("{");
	first = 1;
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		while (curr != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", curr->key, curr->value);
			first = 0;
			curr = curr->next;
		}
	}
	printf("}\n");
}
