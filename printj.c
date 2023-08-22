#include "main.h"

/**
 * print_integer - Print a number in base 10
 * @list: Number to print in base 10
 * Esther
 * Return: Length of th numbers in decimal
 **/
int print_integer(va_list list)
{
	char *p;
	int s;

	p = itoa(va_arg(list, int), 10);

	s = print((p != NULL) ? p : "NULL");

	return (s);
}
