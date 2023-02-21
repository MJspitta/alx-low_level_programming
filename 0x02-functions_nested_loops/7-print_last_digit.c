#include "main.h"

/**
 * print_last_digit - Check description
 * @r: An integer input
 * Description: print the last digit of a number
 * Return: last digit of number r
 */
int print_last_digit(int r)
{
	int num;

	if (r < 0)
		num = -1 * (r % 10);
	else
		num = r % 10;

	_putchar((num % 10) + '0');
	return (num % 10);
}
