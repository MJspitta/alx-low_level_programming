#include "main.h"

/**
 * _islower - Check description
 * @c: input character
 * Description: check for lowercase characters
 * Return: 1 if is lowercase or 0 if is uppercase
 */
int _islower(int c)
{
	char i;
	int low = 0;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (c == i)
			low = 1;
	}

	return (low);
}
