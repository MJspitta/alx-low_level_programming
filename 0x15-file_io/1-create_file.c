#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of file to create
 * @text_content: string to write to file
 *
 * Return: 1 (success) or -1 (failure)
 */
int create_file(const char *filename, char *text_content)
{
	int fildes, n, n_write;

	if (filename == NULL)
		return (-1);

	fildes = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fildes == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	n = 0;
	while (text_content[n])
		n++;

	n_write = write(fildes, text_content, n);
	if (n_write == -1)
		return (-1);

	close(fildes);

	return (1);
}
