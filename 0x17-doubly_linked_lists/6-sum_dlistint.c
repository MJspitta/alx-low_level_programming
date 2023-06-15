#include "lists.h"

/**
 * sum_dlistint - sum of all data in linked list
 * @head: head pointer
 *
 * Return: list sum or 0 (list is empty)
 */
int sum_dlistint(dlistint_t *head)
{
	int listsum;

	listsum = 0;
	while (head != NULL)
	{
		listsum += head->n;
		head = head->next;
	}

	return (listsum);
}
