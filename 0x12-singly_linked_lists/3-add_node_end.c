#include "lists.h"

unsigned int get_len(const char *str);

/**
 * add_node_end - add node to end of list
 * @head: pointer to head node
 * @str: string pointer
 *
 * Return: new element address or NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *last;
	unsigned int len;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	len = get_len(str);
	last = *head;

	new->str = strdup(str);
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new;

	return (*head);
}

/**
 * get_len - length of string
 * @str: string
 *
 * Return: length of string
 */
unsigned int get_len(const char *str)
{
	unsigned int i, len = 0;

	if (str == NULL)
		return (0);

	i = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}
