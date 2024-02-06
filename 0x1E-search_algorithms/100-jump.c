#include "search_algos.h"

/**
 * jump_search - search for value in array using jump search
 * @array: pointer to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index or NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump, p = 0, i;

	jump = sqrt(size);
	if (array == NULL || size == 0)
		return (-1);
	while (array[p] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", p, array[p]);
		if (p + jump >= size)
			break;
		if (array[p + jump] >= value)
			break;
		p += jump;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", p, p + jump);
	for (i = p; i < size && i <= p + jump; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
