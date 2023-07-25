#include "main.h"

/**
 * get_flags - Calc active flags
 * @format: formatted string into which the arguments will be printed
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, present_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (present_i = *i + 1; format[present_i] != '\0'; present_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[present_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = present_i - 1;

	return (flags);
}

