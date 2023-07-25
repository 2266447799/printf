#include "main.h"

/**
 * handle_width - determines the printing width.
 *
 * @format: character string to print arguments.
 * @i: List of arguments to be printed.
 * @args: list of arguments.
 *
 * Return: width.
 */
int handle_width(const char *format, int *i, va_list args)
{
	int curr_i;
	int width = 0;

	/* iterate through the format string */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i])) /* handle digits */
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		/* take width values from arguments */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}

