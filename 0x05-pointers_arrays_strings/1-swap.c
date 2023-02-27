#include "main.h"
#include <string.h>

/**
 * swap_int - swap value of two integers
 * @a: integer pointer
 * @b: integer pointer
 * Return: nothing
 */
void swap_int(int *a, int *b)
{
	int swp;

	swp = *a;
	*a = *b;
	*b = swp;
}
