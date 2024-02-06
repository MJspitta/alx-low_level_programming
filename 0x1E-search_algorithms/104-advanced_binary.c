#include "search_algos.h"

/**
 * advanced_binary_recursive - recursive helper func
 * @array: pointer to first element of array
 * @l: index of left boundary
 * @r: index of right boundary
 * @value: value to search for
 * Return: index or -1
 */
int advanced_binary_recursive(int *array, size_t l, size_t r, int value)
{
	size_t m, i;

	if (l <= r)
	{
		printf("Searching in array: ");
		for (i = l; i < r; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[r]);
		m = (l + r) / 2;
		if (array[m] == value)
		{
			if (m == 0 || array[m - 1] != value)
				return (m);
			else
				return (advanced_binary_recursive(array, l, m, value));
		}
		else if (array[m] < value)
			return (advanced_binary_recursive(array, m + 1, r, value));
		else
			return (advanced_binary_recursive(array, l, m - 1, value));
	}
	return (-1);
}

/**
 * advanced_binary - search for value in array of ints
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
