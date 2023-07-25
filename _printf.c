#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printf-like function.
 *
 * @format: character string format.
 *
 * Return: number of printed chars.
 */
int _printf(const char *format, ...)
{
	int i, chars_printed = 0, printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = handle_flags(format, &i);
			width = handle_width(format, &i, args);
			precision = handle_precision(format, &i, args);
			size = handle_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
														 flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_printed += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (chars_printed);
}

/**
 * print_buffer - prints contents of existing buffer array.
 *
 * @buffer: array of chars.
 * @buff_ind: buffer index for next char (same as buffer length).
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

