#include "main.h"

/**
 * _isalpha - Check description
 * @c: input character
 * Description: check for alphabetic characters
 * Return: 1 if is a letter or 0 otherwise
 */
int _isalpha(int c)
{
	char low, up;
	int letter = 0;

	for (low = 'a'; low <= 'z'; low++)
	{
		for (up = 'A'; up <= 'Z'; up++)
		{
			if (c == low || c == up)
				letter = 1;
		}
	}
	return (letter);
}
