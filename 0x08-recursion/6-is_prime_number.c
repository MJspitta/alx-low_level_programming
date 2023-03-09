#include "main.h"

int _divisible(int, int);

/**
 * is_prime_number - determine a prime number
 * @n: number
 *
 * Return: 1 (prime) or 0
 */
int is_prime_number(int n)
{
	int d = 2;

	if (n <= 1)
		return (0);

	if (n <= 3)
		return (1);

	return (_divisible(n, d));
}

/**
 * _divisible - check if numb is divisible
 * @num: number
 * @div: divisor
 *
 * Return: 1 or 0
 */
int _divisible(int num, int div)
{
	if (num % div == 0)
		return (0);

	if (num / 2 == div)
		return (1);

	return (_divisible(num, div + 1));
}
