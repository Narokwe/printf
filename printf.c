#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Is a character string. The format string
 * is composed of zero or more directives
 *OdenyiMuchai Alias OM
 * Return: The number of characters printed (excluding
 * the null byte used to end output to strings)
 **/
int _printf(const char *format, ...)
{
	int sizeom;
	va_list argsom;

	if (format == NULL)
		return (-1);

	sizeom = _strlen(format);
	if (sizeom <= 0)
		return (0);

	va_start(argsom, format);
	sizeom = handler(format, argsom);

	_putchar(-1);
	va_end(argsom);

	return (sizeom);
}
