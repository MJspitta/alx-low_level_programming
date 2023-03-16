#include <stdlib.h>
#include "main.h"

/**
 * array_range - create array of integers
 * @min: first integer
 * @max: last integer
 *
 * Return: array
 */
int *array_range(int min, int max)
{
	int *ptr, i;

	if (min > max)
		return (NULL);
	if (max - min == 0)
	{
		ptr = malloc(sizeof(int));
		ptr[0] = min;
	}
	else
	{
		ptr = malloc(sizeof(int) * (max - min + 1));
		if (ptr == NULL)
			return (NULL);
		for (i = 0; min <= max; min++, i++)
			ptr[i] = min;
	}

	return (ptr);
}
