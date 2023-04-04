#include "lists.h"

/**
 * get_nodeint_at_index - return nth node of linked list
 * @head: pointer to head
 * @index: index of node to be found
 *
 * Return: nth node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *tmp;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	while (i <= index && head != NULL)
	{
		tmp = head;
		head = head->next;
		i++;
	}
	if (i < index)
		return (NULL);

	return (tmp);
}
