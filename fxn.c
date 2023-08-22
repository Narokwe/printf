#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char z = va_arg(types, int);

	return (handle_write_zhar(z, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int mag = 0, i;
	char *p = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if p == (NULL)
	{
		p = "(null)";
		if (precision >= 6)
			p = "      ";
	}

	while (p[mag] != '\0')
		mag++;

	if (precision >= 0 && precision < mag)
		mag = precision;

	if (width > mag)
	{
		if (flags & F_MINUS)
		{
			write(1, &p[0], mag);
			for (i = width - mag; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - mag; i > 0; i--)
				write(1, " ", 1);
			write(1, &p[0], mag);
			return (width);
		}
	}

	return (write(1, p, mag));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	int is_negative = 0;
	long int s = va_arg(types, long int);
	unsigned long int num;

	s = convert_size_number(s, size);

	if (s == 0)
		buffer[q--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)s;

	if (s < 0)
	{
		num = (unsigned long int)((-1) * s);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[q--] = (num % 10) + '0';
		num /= 10;
	}

	q++;

	return (write_number(is_negative, q, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int v, r, k, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	v = va_arg(types, unsigned int);
	r = 2147483648; /* (2 ^ 31) */
	a[0] = v / r;
	for (k = 1; k < 32; k++)
	{
		r /= 2;
		a[k] = (v / r) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += a[k];
		if (sum || k == 31)
		{
			char z = '0' + a[k];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
