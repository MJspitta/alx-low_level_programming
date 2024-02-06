#include "search_algos.h"

/**
 * binary_search - search for val in array using binary search
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index or NULL(-1)
 */
int binary_search(int *array, size_t size, int value)
{
	int l = 0, h = size - 1, m, i;

	if (array == NULL || size == 0)
		return (-1);
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
