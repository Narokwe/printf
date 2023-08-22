#include "main.h"

/**
 * handler - Format controller
 * @str: String format philani
 * @list: List of arguments
 * Esther 
 * Return: Total size of arguments with the total size of the base string
 **/
int handler(const char *str, va_list list)
{
	int sizepen, z, auxiliary;

	sizepen = 0;
	for (z = 0; str[z] != 0; z++)
	{
		if (str[z] == '%')
		{
			auxiliary = percent_handler(str, list, &z);
			if (auxiliary == -1)
				return (-1);

			sizepen += auxiliary;
			continue;
		}

		_putchar(str[z]);
		sizepen = sizepen + 1;
	}


	return (sizepen);
}

/**
 * percent_handler - Controller for percent format
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 *
 * Return: Size of the numbers of elements printed
 **/
int percent_handler(const char *str, va_list list, int *i)
{
	int sizepen, z, number_fom;
	format form[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexadecimal_low},
		{'X', print_hexadecimal_upp}, {'p', print_pointer},
		{'r', print_rev_string}, {'R', print_rot}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	number_fom = sizeof(form) / sizeof(form[0]);
	for (sizepen = z = 0; z < number_fom; z++)
	{
		if (str[*i] == form[z].type)
		{
			sizepen = form[z].f(list);
			return (sizepen);
		}

	}

	_putchar('%'), _putchar(str[*i]);

	return (2);
}
