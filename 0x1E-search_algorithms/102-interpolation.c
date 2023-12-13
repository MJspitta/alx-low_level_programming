#include "search_algos.h"

/**
 * interpolation_search - seaches for value using interpolation search
 * @array: pointer to first element of array
 * @size: size of array
 * @value: value to search for
 * Return: index or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	int l = 0, h = size - 1;
	size_t idx;

	if (array == NULL)
		return (-1);
	while (l <= h && value >= array[l] && value <= array[h])
	{
		if (l == h)
		{
			if (array[l] == value)
			{
				printf("Value checked array[%d] = [%d]\n", l, array[l]);
				return (l);
			}
			return (-1);
		}
		idx = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
		if (array[idx] == value)
			return (idx);
		else if (array[idx] < value)
			l = idx + 1;
		else
			h = idx - 1;
	}
	printf("Value checked array[%d] is out of range\n", h);
	return (-1);
}
