#include "search_algos.h"

/**
 * interpolation_search - search for value using interpolation search
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index or NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t l = 0, h = size - 1, pos;

	if (array == NULL || size == 0)
		return (-1);
	while (l <= h && value >= array[l] && value <= array[h])
	{
		pos = l + (((double)(h - l) / (array[h] - array[l]))
				* (value - array[l]));
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			l = pos + 1;
		else
			h = pos - 1;
	}
	printf("Value checked array[%ld] is out of range\n", l);
	return (-1);
}
