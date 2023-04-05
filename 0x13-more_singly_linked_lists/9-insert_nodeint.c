#include "lists.h"

/**
 * insert_nodeint_at_index - insert new node at given position
 * @head: pointer to head address
 * @idx: index of list where new node should be added
 * @n: new node
 *
 * Return: Address of new node or NULL (failed)
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode;
	listint_t *current = *head;
	unsigned int i;

	newnode = malloc(sizeof(listint_t));
	if (!newnode || !head)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	for (i = 0; (current != NULL) && (i < idx); i++)
	{
		if (i == idx - 1)
		{
			newnode->next = current->next;
			current->next = newnode;
			return (newnode);
		}
		else
			current = current->next;
	}

	return (NULL);
}
