#include "main.h"

/**
 * get_width - Calc width for printing
 * @format: which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int gw_i;
	int width = 0;

	for (gw_i = *i + 1; format[gw_i] != '\0'; gw_i++)
	{
		if (is_digit(format[gw_i]))
		{
			width *= 10;
			width += format[gw_i] - '0';
		}
		else if (format[gw_i] == '*')
		{
			gw_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = gw_i - 1;

	return (width);
}
