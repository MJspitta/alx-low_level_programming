#include "main.h"

/**
 * print_binary - print binary representation of a number
 * @n: number
 *
 * Return: nothing
 */
void print_binary(unsigned long int n)
{
	static int i;
	int tmp;

	if (i > 0 && n == 0)
		return;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	tmp = n & 1;
	i++;
	print_binary(n >>= 1);
	_putchar(tmp + '0');
}
