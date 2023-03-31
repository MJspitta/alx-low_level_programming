#include "lists.h"

/**
 * list_len - number of elements in list
 * @h: pointer to node
 *
 * Return: number of elements in linked list
 */
size_t list_len(const list_t *h)
{
	unsigned int i;

	i = 0;
	while (h != NULL)
	{
		i++;
		h = h->next;
	}

	return (i);
}
