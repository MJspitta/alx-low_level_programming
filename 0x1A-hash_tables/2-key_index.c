#include "hash_tables.h"

/**
 * key_index - gives you the index of a key
 * @key: the key
 * @size: size of array of hash table
 *
 * Return: the index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int h_value, index;

	h_value = hash_djb2(key);
	index = h_value % size;

	return (index);
}
