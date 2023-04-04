#include "lists.h"

/**
 * free_listint2 - free list and set head to NULL
 * @head: pointer to head address
 *
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	free(*head);
	head = NULL;
}
