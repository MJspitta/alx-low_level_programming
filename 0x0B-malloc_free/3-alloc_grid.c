#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - 2 dimensional array of integers
 * @width: width of array
 * @height: height of array
 *
 * Return: grid (Success) NULL (Failure)
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **ar;

	if (height <= 0 || width <= 0)
		return (NULL);

	ar = (int **) malloc(sizeof(int *) * height);
	if (ar == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		ar[i] = (int *) malloc(sizeof(int) * width);
		if (ar[i] == NULL)
		{
			free(ar);

			for (j = 0; j <= i; j++)
				free(ar[j]);

			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			ar[i][j] = 0;
		}
	}

	return (ar);
}
