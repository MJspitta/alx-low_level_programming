#include "3-calc.h"

/**
 * main - starting point
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%d\n", get_op_func(argv[2])(atoi(argv[1]), atoi(argv[3])));
		return (0);
	}
	printf("Error\n");
	return (98);
}
