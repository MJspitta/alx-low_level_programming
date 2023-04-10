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

	bitstat = (n >> index) & 1;

	return (bitstat);
}
