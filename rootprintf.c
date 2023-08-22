#include "main.h"


/**
 * _strlen - Calculate the length of a string
 * @str: String
 *
 * Return: Length
 **/
int _strlen(const char *str)
{
	int z;

	for (z = 0; str[z] != 0; z++)
		;

	return (z);
}

/**
 * print - print char.
 * @str: string.
 *
 * Return: string length.
 */

int print(char *str)
{
	int z;

	for (z = 0; str[z] != '\0'; ++z)
		_putchar(str[z]);

	return (z);
}
