#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long fib1 = 0, fib2 = 1, sum;
	unsigned long fib1_h1, fib1_h2, fib2_h1, fib2_h2;
	unsigned long h1, h2;

	for (i = 0; i < 92; i++)
	{
		sum = fib1 + fib2;
		printf("%lu, ", sum);

		fib1 = fib2;
		fib2 = sum;
	}

	fib1_h1 = fib1 / 10000000000;
	fib2_h1 = fib2 / 10000000000;
	fib1_h2 = fib1 % 10000000000;
	fib2_h2 = fib2 % 10000000000;

	for (i = 93; i < 99; i++)
	{
		h1 = fib1_h1 + fib2_h1;
		h2 = fib1_h2 + fib2_h2;
		if (fib1_h2 + fib2_h2 > 9999999999)
		{
			h1 += 1;
			h2 %= 10000000000;
		}

		printf("%lu%lu", h1, h2);
		if (i != 98)
			printf(", ");

		fib1_h1 = fib2_h1;
		fib1_h2 = fib2_h2;
		fib2_h1 = h1;
		fib2_h2 = h2;
	}
	printf("\n");

	return (0);
}
