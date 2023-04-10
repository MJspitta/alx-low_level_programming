#include "main.h"

void err_fil(int f_from, int f_to, char *argv[]);

/**
 * main - program starts from here
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, close_error;
	char cbuff[1024];
	ssize_t numchar, wr_f;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	err_fil(file_from, file_to, argv);

	numchar = 1024;
	while (numchar == 1024)
	{
		numchar = read(file_from, cbuff, 1024);
		if (numchar == -1)
			err_fil(-1, 0, argv);
		wr_f = write(file_to, cbuff, numchar);
		if (wr_f == -1)
			err_fil(0, -1, argv);
	}

	close_error = close(file_from);
	if (close_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	close_error = close(file_to);
	if (close_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	return (0);
}

/**
 * err_fil - to check if file can be opened
 * @f_from: source file
 * @f_to: destination file
 * @argv: argument vector
 *
 * Return: nothing
 */
void err_fil(int f_from, int f_to, char *argv[])
{
	if (f_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (f_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
