#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: destination string
 * @src: source string
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
	int d, s;

	d = 0;
	while (*(dest + d) != '\0')
	{
		d++;
	}
	s = 0;
	while(*(src + s) != '\0' && d < 98)
	{
		*(dest + d) = *(src + s);
		d++;
		s++;
	}
	*(dest + d) = '\0';
	return (dest);
}
