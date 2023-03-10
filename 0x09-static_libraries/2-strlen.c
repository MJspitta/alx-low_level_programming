#include "main.h"

/**
 * _strlen - return length of string
 * @s: character pointer
 * Return: string length
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
