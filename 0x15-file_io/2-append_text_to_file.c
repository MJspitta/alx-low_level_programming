#include "main.h"

/**
 * append_text_to_file - append text to end of a file
 * @filename: filename pointer
 * @text_content: content pointer
 *
 * Return: 1 (success) or -1 (failure)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fildes, letters, wr_f;

	if (!filename)
		return (-1);

	fildes = open(filename, O_WRONLY | O_APPEND);

	if (fildes == -1)
		return (-1);
	if (text_content)
	{
		for (letters = 0; text_content[letters]; letters++)
			;

		wr_f = write(fildes, text_content, letters);

		if (wr_f == -1)
			return (-1);
	}
	close(fildes);

	return (1);
}
