#include "main.h"

/**
 * is_prntbl - Evaluates if char is printable
 * @c: Evaluated char
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_prntbl(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Hexadecimal code appended in ASCI to buffer
 * @buffer: Chars array
 * @i: Index to start appending.
 * @asci_code: ASCI code
 * Return: Always 3
 */
int append_hexa_code(char asci_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (asci_code < 0)
		asci_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[asci_code / 16];
	buffer[i] = map_to[asci_code % 16];

	return (3);
}

/**
 * is_digit - Verifies digit as char
 * @c: Evaluated char
 *
 * Return: 1 if c digit, else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_num - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - Number casted to specified size
 * @num: Casted number
 * @size: Indicate the type to be casted
 *
 * Return: Value of num casted
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
