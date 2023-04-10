#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 (big endian) or 1 (little endian)
 */
int get_endianness(void)
{
	unsigned int i;
	char *c;

	i = 1;
	c = (char *) &i;

	return ((int)*c);
}
