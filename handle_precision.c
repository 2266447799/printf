#include "main.h"

/**
 * handle_precision - determine the printing precisions.
 * (i.e the number of digit to be printed after decimal point).
 *
 * @format: Formatted string in which to print the arguments.
 * @i: args of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: Precision.
 */
int handle_precision(const char *format, int *i, va_list args)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* iterate through the format string */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			/* handle multi-digit precision values */
			precision += format[curr_i] - '0';
		}
		/* take precision values from arguments */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

