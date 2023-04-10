#include "main.h"

/**
 * get_bit - get value of bit at given index
 * @n: number
 * @index: index
 *
 * Return: value of bit at index or -1 (error)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bitstat;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	bitstat = (n >> index) & 1;

	return (bitstat);
}
