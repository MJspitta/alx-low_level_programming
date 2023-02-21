#include "main.h"

/**
 * _islower - Entry point
 *
 * Return: 1 (Success) 
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
