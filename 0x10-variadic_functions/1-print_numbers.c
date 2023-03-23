#include "variadic_functions.h"

/**
 * print_numbers - print numbers
 * @separator: pointer to string between numbers
 * @n: numbers of int
 *
 * Return: nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbs;
	unsigned int i;

	va_start(numbs, n);
	for (i = 0; i < n; i++)
	{
		if (i > 0 && separator != NULL)
			printf("%s", separator);
		printf("%d", va_arg(numbs, int));
	}
	va_end(numbs);
	printf("\n");
}
