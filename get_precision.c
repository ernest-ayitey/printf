#include "main.h"

/**
 * get_precision - Calc the precision for printing
 * @format:  arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int pn_i = *i + 1;
	int precision = -1;

	if (format[pn_i] != '.')
		return (precision);

	precision = 0;

	for (pn_i += 1; format[pn_i] != '\0'; pn_i++)
	{
		if (is_digit(format[pn_i]))
		{
			precision *= 10;
			precision += format[pn_i] - '0';
		}
		else if (format[pn_i] == '*')
		{
			pn_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = pn_i - 1;

	return (precision);
}
