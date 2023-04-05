#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at index in list
 * @head: pointer to head address
 * @index: index of node to be deleted
 *
 * Return: 1 (Success) or -1 (Failed)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp;
	listint_t *current = *head;
	unsigned int i;

	if (!head || !(*head))
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	for (i = 0; current && (i <= index); i++)
	{
		if (i == index)
		{
			tmp->next = current->next;
			free(current);
			return (1);
		}
		else
		{
			tmp = current;
			current = current->next;
		}
	}

	return (-1);
}
