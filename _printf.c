#include "main.h"

void prnt_buffer(char buffer[], int *buff_ind);

/**
 * _printf - produces output according to a format
 * @format: Format
 *
 * Return: the number of characters printed
 *(excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				prnt_buffer(buffer, &buff_ind);

			printed_chars++;
		}
		else
		{
			prnt_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list,
					buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;

		}
	}

	prnt_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
* prnt_buffer - Prints buffer contents that exist
* @buffer: Array of characters
* @buff_ind: Length
*/

	void prnt_buffer(char buffer[], int *buff_ind)
	{
		if (*buff_ind > 0)
			write(1, &buffer[0], *buff_ind);

		*buff_ind = 0;
	}

