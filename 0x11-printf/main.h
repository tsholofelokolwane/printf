#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*SIZES*/
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - Structure operation
 *
 * @fmt: Format
 * @fn: Associated function
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Structure operation
 *
 * @fmt: Format
 * @fm_t: Associated function
 */

typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *indx, va_list list,
		char buffer[], int flags, int width, int precision, int size);

/*FUNCTIONS*/

/*Functions to print characters and strings*/
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list, char buffer[],
		int flags, int width, int precision, int size);

/*Functions to print numbers*/
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsgn(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upp(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/*Functions to print non printable characters*/
int prnt_non_printbl(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Functions to print memory address*/
int prnt_pntrs(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Functions to handle other specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int prnt_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int prnt_rot13str(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Width Handler*/
int handle_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags,
		int width, int precision, int length, char padd, char extra_c);
int write_pntr(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgn(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);

/*UTILS*/
int is_prntbl(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsgn(unsigned long int num, int size);

#endif/*MAIN_H*/
