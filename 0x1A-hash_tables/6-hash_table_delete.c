#include "hash_tables.h"

/**
 * hash_table_delete - deletes hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *curr;
	hash_node_t *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		curr = ht->array[i];
		while (curr != NULL)
		{
			tmp = curr;
			curr = curr->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
