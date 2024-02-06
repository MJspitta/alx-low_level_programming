#include "search_algos.h"

/**
 * linear_skip - search for value in sorted skip list of ints
 * @list: pointer to head of list
 * @value: value to search for
 * Return: pointer to first node or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr, *prev;

	if (list == NULL)
		return (NULL);
	curr = list;
	while (curr != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n >= value || curr->express == NULL)
			break;
		prev = curr;
		curr = curr->express;
	}
	if (curr->n >= value || curr->express == NULL)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
				prev->index, curr->index);
		while (prev->index <= curr->index)
		{
			printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
			if (prev->n == value)
				return (prev);
			if (prev->n > value)
				return (NULL);
			prev = prev->next;
		}
	}
	printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, curr->index);
	while (prev->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
