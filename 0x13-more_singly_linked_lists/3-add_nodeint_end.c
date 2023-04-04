#include "lists.h"

/**
 * add_nodeint_end - add new node at end of list
 * @head: pointer to head address
 * @n: new node
 *
 * Return: address of new element or NULL (failed)
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode = malloc(sizeof(listint_t));
	listint_t *lastnode;

	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		lastnode = *head;
		while (lastnode->next != NULL)
		{
			lastnode = lastnode->next;
		}
		lastnode->next = newnode;
	}

	return (*head);
}
