#include "main.h"

/**
 * get_size - Calc the size for the  argument
 * @format: string format in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int gs_i = *i + 1;
	int size = 0;

	if (format[gs_i] == 'l')
		size = S_LONG;
	else if (format[gs_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = gs_i - 1;
	else
		*i = gs_i;

	return (size);
}
