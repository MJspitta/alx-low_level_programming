#include "lists.h"

/**
 * get_dnodeint_at_index - get node at index
 * @head: head pointer
 * @index: index of node
 *
 * Return: nth node or NULL (does not exist)
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int counter;

	counter = 0;
	while (head != NULL)
	{
		if (counter == index)
			return (head);
		counter++;
		head = head->next;
	}

	return (NULL);
}
