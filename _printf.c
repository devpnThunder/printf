#include "main.h"

/**
* _printf - function that works like printf
* @format: pointer to a function
*
* Return: the counter
*/

int _print(const char *format, ...)
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
				int c = va_arg(args, int);
				_putchar(c);
				counter++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);
				while (*s)
				{
					_putchar(*s);
					s++;
					counter++;
				}
			}
			format++;
		}
		va_end(args);
	}
	return counter;
}
