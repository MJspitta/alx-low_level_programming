#include "variadic_functions.h"

/**
 * print_all - print anything
 * @format: format of argument
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	unsigned int i, j, sep = 0;
	char *str;
	char argus[] = "cifs";
	va_list all;

	va_start(all, format);
	i = 0;
	while (format && format[i])
	{
		j = 0;
		while (argus[j])
		{
			if (format[i] == argus[j] && sep)
			{
				printf(", ");
				break;
			} j++;
		}
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(all, int)), sep = 1;
				break;
			case 'i':
				printf("%d", va_arg(all, int)), sep = 1;
				break;
			case 'f':
				printf("%f", va_arg(all, double)), sep = 1;
				break;
			case 's':
				str = va_arg(all, char *), sep = 1;
				if (!str)
				{
					printf("(nil)");
					break;
				}
				printf("%s", str);
				break;
		} i++;
	} va_end(all), printf("\n");
}
