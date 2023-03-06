#include "main.h"

/**
 * _strchr - locate a character in string
 * @s: string pointer
 * @c: character
 *
 * Return: s
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) == c)
		{
			return (s + i);
		}
	}
	if (*(s + i) == c)
		return (s + i);

	return (0);
}
