#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initialize var of type struct dog
 * @d: pointer to struct
 * @name: pointer to name
 * @age: float value of age
 * @owner: pointer to owner
 *
 * Return: nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		(*d).name = name;
		(*d).age = age;
		(*d).owner = owner;
	}
}
