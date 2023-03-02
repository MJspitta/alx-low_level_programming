#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	int i, j;

	i = j = 0;
	while (*(s1 + i) != '\0')
		i++;
	while (*(s2 + j) != '\0')
		j++;
	if(i == j)
		return (0);
	else
		return (i - j);
}
