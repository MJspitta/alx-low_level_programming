#include "main.h"

/**
 * get_endianness - check the endianness
 *
 * Return: 0 (big endian) or 1 (little endian)
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c;

	c = (char *) &i;

	return ((int) *c);
}
