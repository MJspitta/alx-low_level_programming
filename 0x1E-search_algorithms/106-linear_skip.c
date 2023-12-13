#include "search_algos.h"

/**
 * linear_skip - search for val in singly linked list using linear skip
 * @list: pointer to head of linked list
 * @value: value to search for
 * Return: pointer to first node where val is or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *jmp;

	if (list == NULL)
		return (NULL);
	for (node = jmp = list; jmp->next != NULL && jmp->n < value;)
	{
		node = jmp;
		if (jmp->express != NULL)
		{
			jmp = jmp->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jmp->index, jmp->n);
		}
		else
		{
			while (jmp->next != NULL)
				jmp = jmp->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jmp->index);
	for (; node->index < jmp->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	return (node->n == value ? node : NULL);
}
