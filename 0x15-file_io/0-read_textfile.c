#include "main.h"

/**
 * read_textfile - read file and print to POSIX standard output
 * @filename: pointer to filename
 * @letters: number of letters to be read and printed
 *
 * Return: number of letter it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fildes;
	char *cbuff;
	ssize_t rd_f, wr_f;

	if (!filename)
		return (0);

	fildes = open(filename, O_RDONLY);

	if (fildes == -1)
		return (0);

	cbuff = malloc(sizeof(char) * letters);
	if (!cbuff)
		return (0);

	rd_f = read(fildes, cbuff, letters);
	wr_f = write(STDOUT_FILENO, cbuff, rd_f);

	close(fildes);

	free(cbuff);

	return (wr_f);
}
