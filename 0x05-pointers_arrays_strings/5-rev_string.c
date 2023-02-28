#include "main.h"

/**
 * rev_string - reverse a string
 * @s: string pointer
 * Return: nothing
 */
void rev_string(char *s)
{
	int l, j;
	char a;

	l = 0;
	while (*(s + l) != '\0')
	{
		l++;
	}
	for (j = 0; j < (l / 2); j++)
	{
		a = *(s + j);
		*(s + j) = *(s + l - j - 1);
		*(s + l - j - 1) = a;
	}
}
