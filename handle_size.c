#include "main.h"

/**
 * handle_size -Calculates the size of argument data type.
 *
 * @format: character string to print arguments.
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int handle_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG; /* lng data type */
	else if (format[curr_i] == 'h')
		size = S_SHORT; /* short data type */

	if (size == 0) /* if size was not found */
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

