#include "lists.h"

/**
 * print_list - print all elements in a list
 * @h: points to node
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	unsigned int i;

	i = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		i++;
		h = h->next;
	}

	return (i);
}
