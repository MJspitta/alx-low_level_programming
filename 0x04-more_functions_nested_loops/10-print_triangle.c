#include "main.h"

/**
 * print_triangle - print traingle
 * @size: size of triangle
 * Return: nothing
 */
void print_triangle(int size)
{
	int i, h, s;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1; i <= size; i++)
		{
			for (s = size - i; s >= 1; s--)
			{
				_putchar(' ');
			}
			for (h = 1; h <= i; h++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
