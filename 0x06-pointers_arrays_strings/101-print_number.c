#include "main.h"

/**
 * print_number - print an integer
 * @n: integer
 * Return: nothing
 */
void print_number(int n)
{
	int i, j, dgt, dgts, pwr;
	unsigned int temp, num, numchar;

	dgt = 0;
	if (n < 0)
	{
		_putchar('-');
		temp = -n;
	}
	else
	{
		temp = n;
	}

	num = temp;
	while (num >= 10)
	{
		num /= 10;
		dgt++;
	}

	dgts = dgt + 1;
	pwr = 1;
	i = 1;
	while (i < dgts)
	{
		pwr *= 10;
		i++;
	}

	j = pwr;
	while (j >= 1)
	{
		numchar = (temp / j) % 10;
		_putchar(numchar + '0');
		j = j / 10;
	}
}
