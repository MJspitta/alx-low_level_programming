#include "search_algos.h"

/**
 * _binary_search - search for value in array using binary search
 * @array: pointer to first element of array
 * @l: index of first element
 * @h: index of last element
 * @value: value to search for
 * Return: index or -1
 */
int _binary_search(int *array, size_t l, size_t h, int value)
{
	size_t m, i;

	while (l <= h)
	{
		printf("Searching in array: ");
		for (i = l; i <= h; i++)
		{
			printf("%d", array[i]);
			if (i < h)
				printf(", ");
		}
		printf("\n");
		m = (l + h) / 2;
		if (array[m] == value)
			return (m);
		else if (array[m] < value)
			l = m + 1;
		else
			h = m - 1;
	}
	return (-1);
}

/**
 * exponential_search - search value in array using exponential search
 * @array: pointre to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index or -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bnd = 1, minint;

	if (array == NULL || size == 0)
		return (-1);
	while (bnd < size && array[bnd] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", bnd, array[bnd]);
		bnd *= 2;
	}
	minint = bnd < size ? bnd : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n",
			bnd / 2, minint);
	return (_binary_search(array, bnd / 2, minint, value));
}
