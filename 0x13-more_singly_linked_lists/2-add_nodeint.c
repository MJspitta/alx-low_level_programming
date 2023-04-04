#include "lists.h"

/**
 * add_nodeint - add new node at beginning of list
 * @head: pointer to pointer head
 * @n: new node
 *
 * Return: Address of new element of NULL (failure)
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = *head;

	*head = newnode;

	return (*head);
}
