#include "lists.h"

/**
 * print_dlistint - print elements of a list
 * @h: head pointer
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t counter;

	counter = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		counter++;
		h = h->next;
	}

	return counter;
}
