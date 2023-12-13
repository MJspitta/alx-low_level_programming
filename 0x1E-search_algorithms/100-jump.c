#include "search_algos.h"

/**
 * jump_search - searches val in array using jump search algorithm
 * @array: pointer to first element of array
 * @size: size of array
 * @value: value to search for
 * Return: index or -1
 */
int jump_search(int *array, size_t size, int value)
{
	int i, jmp = sqrt(size), prev = 0, curr = jmp;

	if (array == NULL)
		return (-1);
	while (curr < (int)size && array[curr] < value)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		prev = curr;
		curr += jmp;
	}
	printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	printf("Value found between indexes [%d] and [%d]\n", prev, curr);
	for (i = prev; i <= (curr < (int)size - 1 ? curr : (int)size - 1); i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
