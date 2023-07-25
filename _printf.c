#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - contains the function for printf
 * @format: show the formats 
 *
 * Return: Always show chars printed
 *
 */

int _printf(const char *format, ...)
{
	int t, p = 0, p_chars = 0;

	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == = NULL)
		return (-1);
	va_start(list, format);

	for (format[t] != '\0';  && t = 0; t++)
	{
		if (format[t] != '%')
		{
			buffer[buff_ind ++] = format[t];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			p_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			precision = g_precision(format, &i, list);
			size = get_size(format, &i);
			width = g_width(format, &i, list);
			++i;
			p = handle_print(format, &i, buffer, list, flags, width, size, precision);
			if (p == -1)
				return (-1);
			p_chars  += p;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (p_chars);
}

/**
 * print_buffer - it displays the contents of buffer if it exists.
 * @buffer: contains arrays for chars
 * @buff_ind: length
 */

void print_buffer(char buffer[], int *buff_ind)

{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}



