#include <stdlib.h>
#include "main.h"

/**
 * argstostr - concatenate all arguments
 * @ac: argument counter
 * @av: argument vector
 *
 * Return: new string (Success) NULL (Error)
 */
char *argstostr(int ac, char **av)
{
	int i = 0, j, k = 0, len = 0;
	char *astr;

	if (ac == 0 || av == NULL)
		return (NULL);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			len++;
			j++;
		}
		len++;
		i++;
	}
	astr = malloc((sizeof(char) * len) + 1);
	if (astr == NULL)
		return (NULL);

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			astr[k] = av[i][j];
			j++, k++;
		}
		astr[k] = '\n';
		k++, i++;
	}
	astr[k] = '\0';
	return (astr);
}
