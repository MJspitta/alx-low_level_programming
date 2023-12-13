#include "search_algos.h"

/**
 * jump_list - search for val in singly linked list using jump search
 * @list: pointer to head of linked list
 * @size: number of nodes in list
 * @value: value to search for
 * Return: pointer to node where val is or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t mov = 0, mov_size = sqrt(size);
	listint_t *node, *jmp;

	if (list == NULL || size == 0)
		return (NULL);
	for (node = jmp = list; jmp->index + 1 < size && jmp->n < value;)
	{
		node = jmp;
		for (mov += mov_size; jmp->index < mov; jmp = jmp->next)
		{
			if (jmp->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jmp->index, jmp->n);
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jmp->index);
	for (; node->index < jmp->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	return (node->n == value ? node : NULL);
}
