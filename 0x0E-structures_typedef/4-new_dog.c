#include <stdlib.h>
#include "dog.h"

unsigned int _strlen(char *s);
void _strcpy(char *dest, char *src);

/**
 * new_dog - creates a new dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 *
 * Return: pointer to type of struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int nlen = _strlen(name), olen = _strlen(owner);
	dog_t *scoob;

	scoob = malloc(sizeof(dog_t));
	if (scoob)
	{
		scoob->name = malloc(sizeof(char) * (nlen + 1));
		if (scoob->name)
		{
			scoob->owner = malloc(sizeof(char) * (olen + 1));
			if (scoob->owner)
			{
				_strcpy(scoob->name, name);
				scoob->age = age;
				_strcpy(scoob->owner, owner);
				return (scoob);
			}
			else
			{
				free(scoob->name);
				free(scoob);
			}
		}
		else
		{
			free(scoob);
		}
	}

	return (NULL);
}

/**
 * _strlen - gets length of string
 * @s: pointer to string
 *
 * Return: string length
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - to copy string
 * @dest: new string pointer
 * @src: string to copy pointer
 *
 * Return: nothing
 */
void _strcpy(char *dest, char *src)
{
	unsigned int i, srclen = _strlen(src);

	for (i = 0; i <= srclen; i++)
		dest[i] = src[i];
}
