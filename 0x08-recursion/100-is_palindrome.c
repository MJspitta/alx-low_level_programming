#include "main.h"

int _length(char *s);
int _check(int n, char *s);

/**
 * is_palindrome - if string is palindrome
 * @s: string
 *
 * Return: 1 if palindrome
 */
int is_palindrome(char *s)
{
	return (_check(1, s));
}

/**
 * _length - length of string
 * @s: string
 *
 * Return: length
 */
int _length(char *s)
{
	int i = 0;

	if (*s)
	{
		i += _length(s + 1);
		return (i += 1);
	}
	return (0);
}

/**
 * _check - check if it is palindrome
 * @n: integer
 * @s: string
 *
 * Return: 1 or 0
 */
int _check(int n, char *s)
{
	if (*s)
	{
		if (*s != s[_length(s) - n])
			return (0);
		return (_check(n + 1, s + 1));
	}
	return (1);
}
