#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Esther philani
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (buffer(c));
}

/**
 * buffer - Save the character in a buffer
 * @c: Character c
 *
 * Return: 1
 **/
int buffer(char c)
{
	static char estherpbuffer[1024];
	static int z;

	if (c == -1 || z == 1024)
	{
		write(1, estherpbuffer, z);
		z = 0;
	}

	if (c != -1)
		estherpbuffer[z++] = c;

	return (1);
}
