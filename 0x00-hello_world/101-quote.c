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
	char myStr[] = "and that peice of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(STDOUT_FILENO, myStr, strlen(myStr));
	return (1);
}
