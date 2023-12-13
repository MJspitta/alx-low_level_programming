#include "search_algos.h"

/**
 * bin_search - searches for val in array using binary search algorithm
 * @array: pointer to first element of array
 * @l: starting index of array
 * @h: ending index of array
 * @value: value to search for
 * Return: index where value is found or -1
 */
int bin_search(int *array, int l, int h, int value)
{
	int i, m;

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
		m = l + (h - l) / 2;
		printf("Value checked array[%d] = [%d]\n", m, array[m]);
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
 * exponential_search - searches for val in array using exponential search
 * @array: pointer to first element of array
 * @size: size of array
 * @value: value to search for
 * Return: index or -1
 */
int exponential_search(int *array, size_t size, int value)
{
	int i, high, low;

	if (array == NULL)
		return (-1);
	if (array[0] == value)
	{
		printf("Value checked array[0] = [%d]\n", array[0]);
		return (0);
	}
	for (i = 1; i < (int)size && array[i] <= value; i *= 2)
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
	high = (i < (int)size) ? i : (int)size - 1;
	low = i / 2;
	printf("Value found between indexes [%d] and [%d]\n", low, high);
	return (bin_search(array, low, high, value));
}
