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
	hash_node_t *curr;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		if (curr != NULL)
		{
			while (curr != NULL)
			{
				if (curr->next != NULL)
					printf("'%s': '%s', ", curr->key, curr->value);
				printf("'%s': '%s'", curr->key, curr->value);
				curr = curr->next;
			}
		}
	}
	printf("}\n");
}
