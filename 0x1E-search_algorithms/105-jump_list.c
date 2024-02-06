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
	size_t jmp, i, prev;
	listint_t *curr;

	jmp = sqrt(size);
	curr = list;
	while (curr->next != NULL && curr->n < value)
	{
		prev = curr->index;
		for (i = 0; curr->next != NULL && i < jmp; i++)
			curr = curr->next;
		printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
		if (curr->n >= value || curr->next == NULL)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev, curr->index);
	printf("Value checked at index [%lu] = [%d]\n", prev, curr->n);
	while (prev < curr->index && curr->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev, curr->n);
		curr = curr->next;
		prev++;
	}
	if (curr != NULL && curr->n == value)
		return (curr);
	return (NULL);
}
