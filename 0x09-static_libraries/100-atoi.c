#include "main.h"
/**
 * _atoi - convert string to integer
 * @s: string pointer
 * Return: integer
 */
int _atoi(char *s)
{
	unsigned int count, i, j, k, len, num, l;
	int a;

	a = 1;
	count = 0;
	num = 0;

	while (*(s + count) != '\0')
		count++;
	for (i = 0; i < count; i++)
	{
		if (*(s + i) <= '9' && *(s + i) >= '0')
			break;
	}
	for (j = i; j < count; j++)
	{
		if (!(*(s + j) <= '9' && *(s + j) >= '0'))
			break;
	}

	for (k = 0; k < i; k++)
	{
		if (*(s + k) == '-')
			a = -a;
	}
	len = j - i;
	l = i;
		while (len >= 1)
	{
		num = num * 10 + (*(s + l) - '0');
		l++;
		len--;
	}
	return (num * a);
}
