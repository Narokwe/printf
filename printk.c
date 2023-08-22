#include "main.h"

/**
 * itoa - integer to ascii
 * @num: num
 * @base: base
 * philani
 * Return: char
 * Esther
 **/
char *itoa(long int num, int base)
{
	static char *array2 = "0123456789abcdef";
	static char buff[50];
	char sin = 0;
	char *pointer;
	unsigned long z = num;

	if (num < 0)
	{
		z = -num;
		sin = '-';
	}
	pointer = &buff[49];
	*pointer = '\0';

	do      {
		*--pointer = array2[z % base];
		z /= base;
	} while (z != 0);

	if (sin)
		*--pointer = sin;
	return (pointer);
}
