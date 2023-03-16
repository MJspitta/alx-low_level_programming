#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int _isdigit(char *s);
int _strlen(char *s);
void handle_error(void);

/**
 * main - multiplies two positive numbers
 * argc: argument count
 * argv: argument vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, *result, i, co, dgt1, dgt2, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !_isdigit(s1) || !_isdigit(s2))
		handle_error();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i =0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >=0; len1--)
	{
		dgt1 = s1[len1] - '0';
		co = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			dgt2 = s2[len2] - '0';
			co += result[len1 + len2 + 1] + (dgt1 * dgt2);
			result[len1 + len2 + 1] = co % 10;
			co /= 10;
		}
		if (co > 0)
			result[len1 + len2 + 1] += co;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if(!a)
		_putchar('0');
	_putchar('\n');
	free(result);

	return (0);
}

/**
 * _isdigit - check if it contains a non digit
 * @s: string
 *
 * Return: 0 (Success) 1 (otherwise)
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * _strlen - length of string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * handle_error - to handle error
 *
 * Return: nothing
 */
void handle_error(void)
{
	printf("Error\n");
	exit(98);
}
