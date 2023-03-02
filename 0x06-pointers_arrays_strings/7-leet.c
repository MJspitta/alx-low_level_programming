#include "main.h"

/**
 * leet - encode a string
 * @s: string prototype
 * Return: char
 */
char *leet(char *s)
{
	char a[] = "aeotlAEOTL";
	char n[] = "4307143071";
	int i, j;

	i = 0;
	while (*(s + i) != '\0')
	{
		for (j = 0; j <= 9; j++)
		{
			if (*(s + i) == a[j])
				*(s + i) = n[j];
		}
		i++;
	}
	return (s);
}
