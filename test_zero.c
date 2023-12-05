#include "main.h"

/**
 * _printf - produces output format
 * @format: is a character string
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int jantee_count = 0, length = 0;
	va_list argument_list;
	char character, *string;

	if (format == NULL)
		return (-1);
	va_start(argument_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			jantee_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				jantee_count++;
			}
			else if (*format == 'c')
			{
				character = va_arg(argument_list, int);
				write(1, &character, 1);
				jantee_count++;
			}
			else if (*format == 's')
			{
				string = va_arg(argument_list, char*);
				while (string[length] != '\0')
					length++;
				write(1, string, length);
				jantee_count += length;
			}
		}
		format++;
	}
	va_end(argument_list);
	return (jantee_count);
}
