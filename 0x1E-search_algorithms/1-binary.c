#include "search_algos.h"

/**
 * binary_search - searches for val in array using binary search algorithm
 * @array: pointer to first element of array
 * @size: size of array
 * @value: value to search for
 * Return: index where value is found or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, m = 0, l = 0, r = size - 1;

	if (array == NULL)
		return (-1);
	while (l <= r)
	{
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			printf("%d", array[i]);
			if (i < r)
				printf(", ");
		}
		printf("\n");
		m = l + (r - l) / 2;
		if (array[m] == value)
			return (m);
		else if (array[m] < value)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}
