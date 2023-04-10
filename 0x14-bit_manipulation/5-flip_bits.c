#include "main.h"

unsigned int count_set_bits(unsigned long int);

/**
 * flip_bits - flip bits to get from a number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits needed to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	return (count_set_bits(n ^ m));
}

/**
 * count_set_bits - length of number
 * @num: number
 *
 * Return: number length
 */
unsigned int count_set_bits(unsigned long int num)
{
	unsigned int i;

	if (num == 0)
		return (0);

	for (i = 0; num != 0; i++)
		num &= (num - 1);

	return (i);
}
