#include "main.h"

/**
 * print_binary - print binary representation of number
 * @n: number
 *
 * Return: nothing
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n / 2);

	_putchar((n & 1) + '0');
}
