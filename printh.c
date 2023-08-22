#include "main.h"

/**
 * print_hexadecimal_low - Print a number in hexadecimal format
 * @list: Number to print
 * PE
 * Return: Length of the number
 **/
int print_hexadecimal_low(va_list list)
{
	char *s;
	int z;

	s = itoa(va_arg(list, unsigned int), 16);

	z = print((s != NULL) ? s : "NULL");

	return (z);
}
