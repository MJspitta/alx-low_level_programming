#include "search_algos.h"

/**
 * linear_search - searches val in array using linear search algorithm
 * @array: array on integers
 * @size: size of array
 * @value: value to search for
 * Return: index where value is found of -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
