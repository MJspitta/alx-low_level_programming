#include "main.h"

/**
 * read_textfile - reads text file and prints
 * @filename: name of file
 * @letters: numbers of letters it should print
 *
 * Return: letters printed or 0 (failure)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fildes;
	char *buffer;
	ssize_t n_read, n_write;

	if (filename == NULL)
		return (0);

	fildes = open(filename, O_RDONLY);
	if (fildes == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	n_read = read(fildes, buffer, letters);
	n_write = write(STDOUT_FILENO, buffer, n_read);

	close(fildes);
	free(buffer);

	return (n_write);
}
