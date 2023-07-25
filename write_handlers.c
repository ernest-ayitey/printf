#include "main.h"

/**
 * get_width - Calc the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int width = 0;
	int present_i;


	for (present_i = *i + 1; format[present_i] != '\0'; present_i++)
	{
		if (is_digit(format[present_i]))
		{
			width *= 10;
			width += format[present_i] - '0';
		}
		else if (format[present_i] == '*')
		{
			present_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = present_i - 1;

	return (width);
}

