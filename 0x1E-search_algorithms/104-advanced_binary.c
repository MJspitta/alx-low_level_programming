#include "search_algos.h"

/**
 * advanced_binary - search for value in array of ints
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t l = 0, m = 0, i = 0, r = size - 1;

	if (array == NULL || size == 0)
		return (-1);
	while (l <= r)
	{
		printf("Searching in array: ");
		for (i = l; i < r; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		m = (l + r) / 2;
		if (array[m] == value)
		{
			if (m == 0 || array[m - 1] != value)
				return (m);
			r = m;
		}
		else if (array[m] < value)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}
