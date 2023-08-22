#include "main.h"

/**
 * print_binary - Print a number in base 2
 * @list: Number to print in base 2
 * esther
 * Return: Length of the numbers in binary
 **/
int print_binary(va_list list)
{
	char *p;
	int s;

	p = itoa(va_arg(list, unsigned int), 2);

	s = print(p);

	return (s);
}
