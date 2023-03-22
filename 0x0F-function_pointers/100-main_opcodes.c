#include "3-calc.h"

/**
 * main - starting point
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 (Success) 1, 2 (Error)
 */
int main(int argc, char **argv)
{
	int i, byts;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	byts = atoi(argv[1]);
	if (byts < 0)
	{
		printf("Error\n");
		return (2);
	}
	for (i = 0; i < byts; i++)
	{
		printf("%02x", ((unsigned char *)main)[i]);
		printf("%c", i < byts - 1 ? ' ' : '\n');
	}

	return (0);
}
