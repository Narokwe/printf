#include "main.h"
/**
 * print_char - print char.
 * @list: va_list.
 * esther
 * Return: 1
 */
int print_char(va_list list)
{
	int a;

	a = va_arg(list, int);

	_putchar(a);

	return (1);
}
