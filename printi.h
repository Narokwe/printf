#include "main.h"

int is_lowercase(char);
char *string_to_upper(char *);

/**
 * print_hexadecimal_upp - 
 * @list: Number to print
 * Esther
 * Return: Length of the number
 **/
int print_hexadecimal_upp(va_list list)
{
	char *a;
	int sizer;

	a = itoa(va_arg(list, unsigned int), 16);
	a = string_to_upper(a);

	sizer = print((a != NULL) ? a : "NULL");

	return (sizer);
}

/**
 * is_lowercase - Check if the character inlower
 * @c: Character
 * Esther
 * Return: 1 or 0
 **/
int is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * string_to_upper - Change the string to uppercase
 * @s: String
 * Esther
 * Return: String uppercase
 **/
char *string_to_upper(char *s)
{
	int z;

	for (z = 0; s[z] != '\0'; z++)
	{
		if (is_lowercase(s[z]))
		{
			s[z] = s[z] - 32;
		}
	}

	return (s);
}
