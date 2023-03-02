#include "main.h"

/**
 * infinite_add - add two strings
 * @n1: first string
 * @n2: second string
 * @r: result buffer
 * @size_r: buffer size
 * Return: char
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, co = 0, a, b, sum, big;
	
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	if (len1 > len2)
		big = len1;
	else
		big = len2;

	if ((big + 1) >= size_r)
		return (0);

	r[big + 1] = '\0';
	
	while (big >= 0)
	{
		a = (n1[len1 - 1] - '0');
		b = (n1[len2 - 1] - '0');
		if (len1 > 0 && len2 > 0)
			sum = a + b + co;
		else if (len1 < 0 && len2 > 0)
			sum = b + co;
		else if (len1 > 0 && len2 < 0)
			sum = a + co;
		else
			sum = co;
		
		if (sum > 9)
		{
			co = sum / 10;
			sum = (sum % 10) + '0';
		}
		else
		{
			co = 0;
			sum = sum + '0';
		}

		r[big] = sum;
		len1--;
		len2--;
		big--;
	}

	if (*(r) != 0)
		return (r);
	else
		return (r + 1);
}
