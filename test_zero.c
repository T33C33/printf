#include "main.h"

/**
 *_printf - produces output format
 *@format: is a character string
 *
 *Return: 0
 *
 */

int _printf(const char *format, ...)
{
	int jantee_count = 0;
	va_list list_of_arg;

	if (format == NULL);
	{
		return (-1);
	}

	va_start(list_of_arg, format);

	while(*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			jantee_count++;
		}
		else
		{
			format++;
		}
		if (*format == 'c')
		{
			int 
