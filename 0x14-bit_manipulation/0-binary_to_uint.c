#include "main.h"

/**
 * binary_to_uint - convert binary to unsigned int
 * @b: pointing to a string of 0 and 1
 *
 * Return: the converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int value;

	if (b == NULL)
		return (0);

	value = 0;
	while (*b)
	{
		if (*b == '1')
			value = (value << 1) | 1;
		else if (*b == '0')
			value <<= 1;
		else
			return (0);
		b++;
	}

	return (value);
}
