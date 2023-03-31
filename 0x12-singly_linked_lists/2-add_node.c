#include "lists.h"

unsigned int get_len(const char *str);

/**
 * add_node - add node at beginning of list
 * @head: first node pointer
 * @str: string pointer
 *
 * Return: pointer to list
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = (list_t *) malloc(sizeof(list_t));
	unsigned int len;

	if (new == NULL)
		return (NULL);

	len = get_len(str);
	new->str = strdup(str);
	new->len = len;
	new->next = (*head);
	(*head) = new;

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
