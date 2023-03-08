#include "main.h"

/**
 * _pow_recursion - value of x to pow y
 * @x: number
 * @y: power
 *
 * Return: value of x raised to pow y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y > 0)
		return (x * _pow_recursion(x, y - 1));
	return (1);
}
