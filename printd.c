#include <stdarg.h>
#include "main.h"

/**
 *_printf - prints to output according to format
 *@format: character string for esther philani
 *Philani and Esther code
 *Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int z = 0, x = 0;
	int (*fom)(va_list);
	va_list epargs;

	va_start(epargs, format);
	if (format == NULL || !format[z + 1])
		return (-1);
	while (format[z])
	{
		if (format[z] == '%')
		{
			if (format[z + 1])
			{
				if (format[z + 1] != 'c' && format[z + 1] != 's'
				&& format[z + 1] != '%' && format[z + 1] != 'd'
				&& format[z + 1] != 'i')
				{
					x += _putchar(format[z]);
					x += _putchar(format[z + 1]);
					z++;
				}
				else
				{
					fom = get_func(&format[z + 1]);
					x += f(epargs);
					z++;
				}
			}
		}
		else
		{
			_putchar(format[z]);
			x++;
		}
		z++;
	}
	va_end(epargs);
	return (x);
}
