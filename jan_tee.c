#include "main.h"
#include "print_function.h"
#include <stdio.h>
/**
 * print_char - prints a character
 * @list: list of arguments
 *
 * Return: number of characters printed
 */
int print_char(va_list list)
{
	char c = va_arg(list, int);

	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @list: list of arguments
 *
 * Return: number of characters printed
 */
int print_string(va_list list)
{
	char *s = va_arg(list, char *);

	return (write(1, s, strlen(s)));
}
/**
 * print_int - prints an integer
 * @list: list of arguments
 *
 * Return: number of characters printed
 */
int print_int(va_list list)
{
	int num = va_arg(list, int);
	char str[12];

	sprintf(str, "%d", num);
	return (write(1, str, strlen(str)));
}

/**
 * _printf - function that produces output according to a format
 * @format: the format string
 *
 * Return: number of char printed
 */
int _printf(const char *format, ...)
{
	va_list argument_list;
	int jantee_count = 0;

	va_start(argument_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					jantee_count += print_char(argument_list);
					break;
				case 's':
					jantee_count += print_string(argument_list);
					break;
				case 'd':
				case 'i':
					jantee_count += print_int(argument_list);
					break;
				case '%':
					jantee_count += write(1, "%", 1);
					break;
			}
		}
		else
		{
			jantee_count += write(1, format, 1);
		}
		format++;
	}
	va_end(argument_list);
	return (jantee_count);
}

