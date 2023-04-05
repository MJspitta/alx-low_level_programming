#include "lists.h"

/**
 * print_listint_safe - print linked list
 * @head: head pointer
 *
 * Return: number of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp = NULL;
	const listint_t *lst = NULL;
	size_t counter = 0;
	size_t new;

	tmp = head;
	while (tmp)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		counter++;
		tmp = tmp->next;
		lst = head;
		new = 0;
		while (new < counter)
		{
			if (tmp == lst)
			{
				printf("-> [%p] %d\n", (void *)tmp, tmp->n);
				return (counter);
			}
			lst = lst->next;
			new++;
		}
		if (!head)
			exit(98);
	}

	return (counter);
}
