#include "main.h"

/**
* print_buf - function that prints items in the buffer
* @buffer: array of characters
* @buf: a pointer to an interger
*
*/

void print_buf(char buffer[], int *buf)
{
	if (*buf > 0)
	{
		for (int i = 0; i < *buf; i++)
		{
			_putchar(buffer[i]);
		}
	}
	*buf = 0;
}
