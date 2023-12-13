#include "search_algos.h"

/**
 * binary_search_recursive - searches recursively for val using binary search
 * @array: pointer to first element in array
 * @l: starting index in array
 * @h: ending index in array
 * @value: value to search for
 * Return: index or -1
 */
int binary_search_recursive(int *array, size_t l, size_t h, int value)
{
	size_t i;

	if (h < l)
		return (-1);
	printf("Searching in array: ");
	for (i = l; i < h; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
	i = l + (h - l) / 2;
	if (array[i] == value && (i == l || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (binary_search_recursive(array, l, i, value));
	return (binary_search_recursive(array, i + 1, h, value));
}

/**
 * advanced_binary - searches for val using advanced binary search
 * @array: pointer to first element of array
 * @size: size of array
 * @value: value to search for
 * Return: index or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (binary_search_recursive(array, 0, size - 1, value));
}
