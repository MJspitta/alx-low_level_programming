#include "main.h"

/**
 * _strlen_recursion - length of a string
 * @s: string pointer
 *
 * Return: string length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	s++;
	return (1 + _strlen_recursion(s));
}
