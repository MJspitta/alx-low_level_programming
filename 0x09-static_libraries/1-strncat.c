#include "main.h"

/**
 * _strncat - concatenate two strings, n bytes
 * @dest: destination string
 * @src: source string
 * @n: size of source string
 * Return: char
 */
char *_strncat(char *dest, char *src, int n)
{
	int d, s;

	d = 0;
	while (*(dest + d) != '\0')
	{
		d++;
	}
	s = 0;
	while (*(src + s) != '\0' && d < 98 && s < n)
	{
		*(dest + d) = *(src + s);
		d++;
		s++;
	}
	*(dest + d) = '\0';
	return (dest);
}
