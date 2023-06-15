#include "lists.h"

/**
 * free_dlistint - free list
 * @head: head pointer
 *
 * Return: nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *currnode, *nextnode;

	currnode = head;
	while (currnode != NULL)
	{
		nextnode = currnode->next;
		free(currnode);
		currnode = nextnode;
	}
}
