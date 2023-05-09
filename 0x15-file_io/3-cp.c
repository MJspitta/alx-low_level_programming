#include "main.h"

void err_message(int src, int dest, char **av);

/**
 * main - the program starts here
 * @ac: argument counter
 * @av: argument vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	int src, dest, close_err;
	ssize_t n_read, n_write;
	char buffer[1024];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	src = open(av[1], O_RDONLY);
	dest = open(av[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	err_message(src, dest, av);

	n_read = 1024;
	while (n_read == 1024)
	{
		n_read = read(src, buffer, 1024);
		if (n_read == -1)
			err_message(-1, 0, av);
		n_write = write(dest, buffer, n_read);
		if (n_write == -1)
			err_message(0, -1, av);
	}
	close_err = close(dest);
	if (close_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src);
		exit(100);
	}
	close_err = close(src);
	if (close_err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest);
		exit(100);
	}

	return (0);
}

/**
 * err_message - source and destination file check errors
 * @src: source file
 * @dest: destination file
 * @av: argument vector
 *
 * Return: nothing
 */
void err_message(int src, int dest, char **av)
{
	if (src == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	if (dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}
}
