#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenate two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 * @n: number of bytes from second string
 *
 * Return: char
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *newstr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (*(s1 + len1) != '\0')
		len1++;
	while (*(s2 + len2) != '\0')
		len2++;
	if (n >= len2)
		n = len2;
	newstr = malloc(sizeof(char) * (len1 + n + 1));
	if (newstr == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newstr[i] = s1[i];
	for (j = 0; j < n; i++, j++)
		newstr[i] = s2[j];
	newstr[i] = '\0';

	return (newstr);
}
