#include "lists.h"

/**
 * free_list - frees a list
 * @head: pointer to head
 *
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		free(head->str);
		head = head->next;
		free(temp);
	}
}
