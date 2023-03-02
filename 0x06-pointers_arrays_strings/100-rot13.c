#include "main.h"

/**
 * rot13 - encode a string
 * @s: string pointer
 * Return: char
 */
char *rot13(char *s)
{
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char r13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	i = 0;
	while (*(s + i) != '\0')
	{
		for (j = 0; j <= 51; j++)
		{
			if (*(s + i) == a[j])
			{
				*(s + i) = r13[j];
				break;
			}
		}
		i++;
	}
	return (s);
}
