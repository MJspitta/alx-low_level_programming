#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 1 (Success)
 */
int main(void)
{
	char a[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(STDOUT_FILENO, a, strlen(a));
	return (1);
}
