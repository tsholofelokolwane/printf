#include "main.h"
/**
 * handle_print - Argument printed based on its type
 * @fmt: Print the arguments in formatted string
 * @list: Arguments list to be printed
 * @indx: Index parameter
 * @buffer: Array of buffer to handle print
 * @flags: Counts number of active flags
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Numbers 1 or 2
 */
int handle_print(const char *fmt, int *indx, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknwn_leng = 0, prntd_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsgn}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upp}, {'p', prnt_pntrs}, {'S', prnt_non_printbl},
		{'r', prnt_reverse}, {'R', prnt_rot13str}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*indx] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*indx] == '\0')
			return (-1);
		unknwn_leng += write(1, "%%", 1);
		if (fmt[*indx - 1] == ' ')
			unknwn_leng += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (fmt[*indx] != ' ' && fmt[*indx] != '%')
				--(*indx);
			if (fmt[*indx] == ' ')
				--(*indx);
			return (1);
		}
		unknwn_leng += write(1, &fmt[*indx], 1);
		return (unknwn_leng);
	}
	return (prntd_chars);
}
