#include "hash_tables.h"

/**
 * free_node_new: to free new node
 * @node: new node
 *
 * Return: nothing
 */
void free_node_new(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: the key
 * @value: value associated with the key
 *
 * Return: 1 (succeeded) or 0 (failed)
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node_new, *curr;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node_new = (hash_node_t *)malloc(sizeof(hash_node_t));
	if (node_new == NULL)
		return (0);

	node_new->key = strdup(key);
	node_new->value = strdup(value);
	node_new->next = NULL;
	if (node_new->key == NULL || node_new->value == NULL)
	{
		free_node_new(node_new);
		return (0);
	}

	curr = ht->array[index];
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
		{
			free_node_new(node_new);

			curr->value = strdup(value);
			if (curr->value == NULL)
				return (0);

			return (1);
		}
		curr = curr->next;
	}
	node_new->next = ht->array[index];
	ht->array[index] = node_new;

	return (1);
}
