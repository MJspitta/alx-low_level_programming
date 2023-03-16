#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocate a memory block
 * @ptr: pointer to prev allocated memory
 * @old_size: allocated space for ptr
 * @new_size: new memory block
 *
 * Return: nothin
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		p[i] = ((char *)ptr)[i];
	free(ptr);

	return (p);
}
