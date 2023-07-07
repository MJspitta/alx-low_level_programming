#include "hash_tables.h"

/**
 * shash_table_create - create sorted hash table
 * @size: size of array
 *
 * Return: pointer to new hash table or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = calloc(size, sizeof(shash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * shash_table_set - add element to sorted hash table
 * @ht: sorted hash table
 * @key: the key
 * @value: value associated with key
 *
 * Return: 1 (succeeded) or 0 (failed)
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node_new, *curr, *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = strdup(value);
			return (1);
		}
		curr = curr->next;
	}
	node_new = malloc(sizeof(shash_node_t));
	if (node_new == NULL)
		return (0);
	node_new->key = strdup(key);
	node_new->value = strdup(value);
	node_new->next = NULL;
	if (node_new->key == NULL || node_new->value == NULL)
	{
		free_snode(node_new);
		return (0);
	}
	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		node_new->sprev = NULL;
		node_new->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = node_new;
		ht->shead = node_new;
		if (ht->stail == NULL)
			ht->stail = node_new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(key, tmp->snext->key) > 0)
			tmp = tmp->snext;
		node_new->sprev = tmp;
		node_new->snext = tmp->snext;
		if (tmp->snext != NULL)
			tmp->snext->sprev = node_new;
		else
			ht->stail = node_new;
		tmp->snext = node_new;
	}
	node_new->next = ht->array[index];
	ht->array[index] = node_new;

	return (1);
}

/**
 * shash_table_get - retrieve a value associated with a key
 * @ht: sorted hash table
 * @key: key to search for
 *
 * Return: value of key or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *curr;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];
	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
		curr = curr->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints sorted hash table
 * @ht: sorted hash table
 *
 * Return: nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	int first;
	shash_node_t *curr;

	if (ht == NULL)
		return;

	first = 1;
	curr = ht->shead;
	printf("{");
	while (curr != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		first = 0;
		curr = curr->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted hash table in reverse
 * @ht: sorted hash table
 *
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	int first;
	shash_node_t *curr;

	if (ht == NULL)
		return;

	first = 1;
	curr = ht->stail;
	printf("{");
	while (curr != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", curr->key, curr->value);
		first = 0;
		curr = curr->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - delete sorted hash table
 * @ht: hash table
 *
 * Return: nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *curr, *tmp;

	if (ht == NULL)
		return;

	curr = ht->shead;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->snext;
		free_snode(tmp);
	}
	free(ht->array);
	free(ht);
}

/**
 * free_snode - free node
 * @node: node
 *
 * Return: nothing
 */
void free_snode(shash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}
