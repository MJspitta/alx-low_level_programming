#include "variadic_functions.h"

/**
 * print_strings - print strings
 * @separator: pointer to string between strings
 * @n: number of strings
 *
 * Return: nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strngs;
	unsigned int i;
	char *str;

	va_start(strngs, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(strngs, char *);
		if (i > 0 && separator != NULL)
			printf("%s", separator);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);
	}
	va_end(strngs);
	printf("\n");
}
