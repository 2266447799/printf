#include "main.h"

/**
 * handle_flags - handles flag characters 4 non-custom conversion specifiers.
 *
 * @format: character string to print arguments.
 * @i: take a parameter.
 *
 * Return: Flags bitwise combination of the flags in the format string()
 */
int handle_flags(const char *format, int *i)
{
	/* 1 2 4 8 16 */
	/* - + 0 # ' ' */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				/* set the corresponding bits in flags to 1 */
				/* if they are 1 in either flags or FLAGS_ARR[j] */
				flags |= FLAGS_ARR[j]; /* bit */
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

