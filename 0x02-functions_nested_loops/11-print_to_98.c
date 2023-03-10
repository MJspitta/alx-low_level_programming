#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - Check description
 * @n: natural number
 * Description: Print all natural numbers from n to 98
 * Return: nothing
 */
void print_to_98(int n)
{
	int i;

	if (n < 98)
	{
		for (i = n; i <= 98; i++)
		{
			printf("%d", i);
			if (i == 98)
				continue;
			printf(", ");
		}
		printf("\n");
	}
	else if (n > 98)
	{
		for (i = n; i >= 98; i--)
		{
			printf("%d", i);
			if (i == 98)
				continue;
			printf(", ");
		}
		printf("\n");
	}
	else
		printf("%d\n", n);
}
