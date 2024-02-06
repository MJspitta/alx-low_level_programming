#include "search_algos.h"

/**
 * jump_list - search for value in list using jump search
 * @list: pointer to head of list
 * @size: number of nodes in list
 * @value: value to search for
 * Return: pointer to first node or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jmp, i;
	listint_t *curr, *prev;

	if (list == NULL || size == 0)
		return (NULL);
	jmp = sqrt(size);
	curr = list;
	while (curr->next != NULL && curr->n < value)
	{
		prev = curr;
		for (i = 0; curr->next != NULL && i < jmp; i++)
			curr = curr->next;
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, curr->index);
	while (prev->index <= curr->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				prev->index, curr->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
		if (prev == NULL || prev->n > value)
			break;
	}
	return (NULL);
}
