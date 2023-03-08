#include "main.h"

int _square(int, int);

/**
 * _sqrt_recursion - natural sqrt of a number
 * @n: number
 *
 * Return: square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_square(1, n));
}

/**
 * _square - find square root
 * @start: integer to check
 * @end: last integer/number
 *
 * Return: square
 */
int _square(int start, int end)
{
	if (start > end)
		return (-1);
	else if (start * start == end)
		return (start);

	return (_square(start + 1, end));
}
