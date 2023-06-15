#include "lists.h"

/**
 * add_dnodeint_end - add new node at the end
 * @head: list head
 * @n: value
 *
 * Return: address of new element of NULL(failed)
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newnode, *currnode;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		currnode = *head;
		while (currnode->next != NULL)
			currnode = currnode->next;
		currnode->next = newnode;
		newnode->prev = currnode;
	}

	return (newnode);
}
