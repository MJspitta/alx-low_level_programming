#include "main.h"

/**
 * set_bit - set value of a bit to 1 at given index
 * @n: pointer to number
 * @index: index
 *
 * Return: 1 (success) or -1 (error)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	mask = 1 << index;

	*n |= mask;

	return (1);
}
