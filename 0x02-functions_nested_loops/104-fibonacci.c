#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long f1 = 0, f2 = 1, s, f1h1, f1h2, f2h1, f2h2, h1, h2;

	for (i = 0; i < 92; i++)
	{
		s = f1 + f2;
		printf("%lu, ", s);
		f1 = f2;
		f2 = s;
	}
	f1h1 = f1 / 10000000000;
	f2h1 = f2 / 10000000000;
	f1h2 = f1 % 10000000000;
	f2h2 = f2 % 10000000000;
	for (i = 93; i < 99; i++)
	{
		h1 = f1h1 + f2h1;
		h2 = f1h2 + f2h2;
		if (f1h2 + f2h2 > 9999999999)
		{
			h1 += 1;
			h2 %= 10000000000;
		}
		printf("%lu%lu", h1, h2);
		if (i != 98)
			printf(", ");
		f1h1 = f2h1;
		f1h2 = f2h2;
		f2h1 = h1;
		f2h2 = h2;
	}
	printf("\n");
	return (0);
}
