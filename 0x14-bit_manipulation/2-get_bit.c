#include "main.h"

/**
 * get_bit - return value of bit at given index
 * @n: number
 * @index: index
 *
 * Return: value of bit at index or -1 (error)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_status;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	bit_status = (n >> index) & 1;

	return (bit_status);
}
