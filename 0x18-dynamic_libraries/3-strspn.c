#include "main.h"

/**
 * _strspn - get length of prefix substring
 * @s: string pointer
 * @accept: character pointer
 *
 * Return: length
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, count, flag;

	count = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		flag = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				flag = 1;
			}
		}
		if (flag == 0)
			return (count);
	}

	return (0);
}
