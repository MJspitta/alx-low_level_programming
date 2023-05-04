#include "main.h"

int count_bits(unsigned long int);

/**
 * flip_bits - number of bits to flip to get from one to another number
 * @n: first number
 * @m: second number
 *
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	return (count_bits(n ^ m));
}

/**
 * count_bits - count set bits
 * @n: number
 *
 * Return: number of bits
 */
int count_bits(unsigned long int n)
{
	int counter = 0;

	while (n > 0)
	{
		counter++;
		n &= (n - 1);
	}

	return (counter);
}
