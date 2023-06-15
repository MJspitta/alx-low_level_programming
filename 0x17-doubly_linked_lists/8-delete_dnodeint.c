#include "lists.h"

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: list head
 * @index: index of node to be deleted
 *
 * Return: 1 (succeeded) or -1 (failed)
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *currnode;
	unsigned int counter;

	if (head == NULL || *head == NULL)
		return (-1);

	currnode = *head;
	if (index == 0)
	{
		*head = currnode->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(currnode);
		return (1);
	}

	counter = 0;
	while (currnode != NULL && counter < index)
	{
		currnode = currnode->next;
		counter++;
	}
	if (currnode == NULL)
		return (-1);
	if (currnode->next != NULL)
		currnode->next->prev = currnode->prev;
	if (currnode->prev != NULL)
		currnode->prev->next = currnode->next;

	free(currnode);

	return (1);
}
