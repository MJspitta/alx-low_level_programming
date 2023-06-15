#include "lists.h"

/**
 * dlistint_len - linked list length
 * @h: header pointer
 *
 * Return: number of elements in a linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t counter;

	counter = 0;
	while (h != NULL)
	{
		counter++;
		h = h->next;
	}

	return (counter);
}
