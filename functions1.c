#include "main.h"

/*PRINT UNSIGNED NUMBER*/
/**
 * print_unsgn - Prints an unsigned number
 * @types: Lists types arguments
 * @buffer: Array of buffer that handles print
 * @flags: Counts flags that are active
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of printed chars
 */
int print_unsgn(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgn(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgn(0, i, buffer, flags, width, precision, size));
}

/*PRINT UNSIGNED NUMBER IN OCTAL NOTATION*/
/**
 * print_octal - Prints unsigned number in octal notation
 * @types: Lists type of arguments
 * @buffer: Array of buffer that handles print
 * @flags:  Counts flags that are active
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgn(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgn(0, i, buffer, flags, width, precision, size));
}

/*PRINT UNSIGNED NUMBER IN HEXADECIMAL NOTATION*/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lists type of arguments
 * @buffer: Array of buffer that handle print
 * @flags:  Counts flags that are active
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upp - Prints an unsigned number in upper hexadecimal notation
 * @types: Lists type of arguments
 * @buffer: Array of buffer that handles print
 * @flags:  Counts flags that are active
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * Return: Number of chars printed
 */
int print_hexa_upp(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* PRINT HEXADECIMAL IN LOWER OR UPPER */
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lists types of arguments
 * @map_to: Array values to map the number to
 * @buffer: Array of buffer to handle print
 * @flags:  Counts number of active flags
 * @flag_ch: Counts number of active flags
 * @width: Width parameter
 * @precision: Precision parameter
 * @size: Size parameter
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgn(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgn(0, i, buffer, flags, width, precision, size));
}
