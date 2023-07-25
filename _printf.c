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

int _print(const char *format, ...)
{
	va_list args;
	char buffer[BUF_SIZE];

	int count = 0;
	int printed = 0;
	int buf = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				buffer[buf++] = '%';
				if (buf == BUF_SIZE)
				{
					print_buf(buffer, &buf);
					count += buf;
				}
			}
			else if (*format == 'c')
			{
				int c = va_arg(args, int);

				buffer[buf++] = c;
				if (buf == BUF_SIZE)
				{
					print_buf(buffer, &buf);
					count += buf;
				}
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					buffer[buf++] = *s;
					s++;
					if (buf == BUF_SIZE)
					{
						print_buf(buffer, &buf);
						count += buf;
					}
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				int val = va_arg(args, int);

				printed = print_int(val);
				count += printed;
			}
		}
		else
		{
			buffer[buf++] = *format;

			if (buf == BUF_SIZE)
			{
				print_buf(buffer, &buf);
				count += buf;
			}
		}
		format++;
	}
	print_buf(buffer, &buf);
	count += buf;

	va_end(args);
	return (count);
}
