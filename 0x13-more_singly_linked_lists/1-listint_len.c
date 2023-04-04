#include "lists.h"

/**
 * listint_len - return number of elements in linked list
 * @h: pointer to node
 *
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	int i;

	i = 0;
	while (h != NULL)
	{
		i++;
		h = h->next;
	}

	return (i);
}
