#include "lists.h"

/**
 * pop_listint - delete head node of linked list
 * @head: pointer to head address
 *
 * Return: head node data
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (0);

	tmp = *head;
	*head = (*head)->next;
	n = tmp->n;
	free(tmp);

	return (n);
}
