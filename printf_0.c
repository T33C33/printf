#include "main.h"

/**
 * _printf -produces output format
 * @format: is a character srting
 * Return: no of characters printed
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
			if (*format == 'c')
			{
				char c = va_arg(argument_list, int);

				jantee_count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *s = va_arg(argument_list, char *);

				jantee_count += write(1, s, strlen(s));
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num_di = va_arg(argument_list, int);
				char str[12];
				sprintf(str, "%d", num_di);

				jantee_count += write(1, str, strlen(str));
			else if (*format == '%')
			{
				jantee_count += write(1, "%", 1);
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

