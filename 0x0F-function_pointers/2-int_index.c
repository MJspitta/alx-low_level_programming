#include "function_pointers.h"

/**
 * int_index - searches for integer
 * @array: pointer to array
 * @size: size of array
 * @cmp: pointer to func used to compare values
 *
 * Return: int
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && size && cmp)
	{
		for (i = 0; i < size; i++)
			if (cmp(array[i]))
				return (i);
	}
	return (-1);
}
