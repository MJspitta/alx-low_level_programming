#include "lists.h"

/**
 * insert_dnodeint_at_index - insert node at index
 * @h: list head
 * @idx: index where new node should be added
 * @n: value
 *
 * Return: address of new node or NULL (failed)
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newnode, *currnode;
	unsigned int counter;

	if (h == NULL)
		return (NULL);

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (idx == 0)
	{
		newnode->next = *h;
		if (*h != NULL)
			(*h)->prev = newnode;
		*h = newnode;
	}
	else
	{
		currnode = *h;
		counter = 0;
		while (currnode != NULL && counter < idx - 1)
		{
			currnode = currnode->next;
			counter++;
		}
		if (currnode == NULL)
			return (NULL);
		newnode->next = currnode->next;
		newnode->prev = currnode;
		if (currnode->next != NULL)
			currnode->next->prev = newnode;

		currnode->next = newnode;
	}

	return (newnode);
}
