#include <stdio.h>
#include <stdlib.h>

/**
 * main - Starting point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	int n1, n2, multiply;

	if (argc != 3)
	{
		printf("%s\n", "Error");
		return (1);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);
	multiply = n1 * n2;

	printf("%d\n", multiply);

	return (0);
}
