#include <stdio.h>
#include "main.h"

/**
 * main - print the biggest prime factor of a number.
 *
 * Return: 0 (Success)
 */
int main(void)
{
	long int number;

	number = 612852475143;

	if (isPrime(number) == 1)
	{
		printf("%ld\n", number);
	}
	else
	{
		printf("%ld\n", biggestFactor(number));
	}
	return (0);
}

/**
 * isPrime - check if a number is prime or not
 * @n: number to check
 * Return: true if it is prime false if not
 */
int isPrime(long int n)
{
	int i;

	if (n <= 1)
	{
		return (0);
	}
	else if (n == 2)
	{
		return (1);
	}
	else
	{
		for (i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				return (0);
			}
		}
	return (1);
	}
}

/**
 * biggestFactor - return the largest prime factor of a number
 * @a: number to check
 * Return: biggest factor
 */
long int biggestFactor(long int a)
{
	long int i;

	for (i = 2; i <= a; i++)
	{
		if (isPrime(a) == 1)
		{
			break;
		}
		else
		{
			if ((a % i == 0) && (isPrime(i) == 1))
			{
				a = a / i;
				continue;
			}
			else
			{
				a = a;
			}
		}
	}
	return (a);
}
