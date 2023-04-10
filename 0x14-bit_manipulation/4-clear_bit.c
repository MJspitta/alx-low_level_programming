#include "main.h"

/**
 * clear_bit - set value of bit to 0 at given index
 * @n: pointer to number
 * @index: index
 *
 * Return: 1 (success) or -1 (error)
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	mask = 1 << index;
	*n = *n & ~mask;

	return (1);
}
