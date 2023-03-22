#include "function_pointers.h"

/**
 * print_name - calls a func to print name
 * @name: pointer to name
 * @f: pointer to func
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
