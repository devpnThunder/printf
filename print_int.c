#include "main.h"

/**
* print_int - function to convert int to character string
* @val: integer variable
*
* Return: conversion value
*/

int print_int(int val)
{
	char buffer[32];
	int printed = snprintf(buffer, sizeof(buffer), "%d", val);

	for (int i = 0; i < printed; i++)
	{
		_putchar(buffer[i]);
	}
	return (printed);
}
