#include "main.h"

/**
 * append_text_to_file - append text to end of file
 * @filename: name of the file
 * @text_content: string to add at end of file
 *
 * Return: 1 (success) or -1 (failure)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fildes, n, n_append;

	if (filename == NULL)
		return (-1);

	fildes = open(filename, O_WRONLY | O_APPEND);
	if (fildes == -1)
		return (-1);

	if (text_content)
	{
		n = 0;
		while (text_content[n])
			n++;

		n_append = write(fildes, text_content, n);
		if (n_append == -1)
			return (-1);
	}

	close(fildes);

	return (1);
}
