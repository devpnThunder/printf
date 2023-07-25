#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#define BUF_SIZE 1024

/**
* _printf - function that works like printf
* @format: pointer to a function
*
* Return: the counter
*/

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				counter++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				_putchar(s);
			}
			format++;
		}
		else
		{
			_putchar(*format);
		}
	}
	va_end(args);
}
