#include "lists.h"

/**
 * print_listint - print all elements of a list
 * @h: pointer to node
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	unsigned int i;

	i = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		i++;
		h = h->next;
	}

	return (i);
}
