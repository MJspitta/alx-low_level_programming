#include "lists.h"

/**
 * free_listint_safe - free a list
 * @h: pointer to head address
 *
 * Return: size of list that was free'dd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *tmp;
	int dif;

	if (!h || !(*h))
		return (0);

	while (*h)
	{
		dif = *h - (*h)->next;
		if (dif > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}
	*h = NULL;

	return (len);
}
