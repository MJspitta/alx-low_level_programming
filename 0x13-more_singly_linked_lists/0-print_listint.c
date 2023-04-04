#include "lists.h"

/**
 * print_listint - print all elements of a list
 * @h: node to pointer
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	int nds;

	nds = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		nds++;
		h = h->next;
	}

	return (nds);
}
