#include "main.h"
/**
 * print_unsigned - functions prints unsigned integers
 * @buffer: the buffer array
 * @flags: the active flags
 * @types: list of arguments
 * @size: the size specifier
 * @precision: precision specifier
 * @width: width specifier
 * return array of chars
 */
int print_unsigned(va_list types, char buffer[],int precision, int width, int size, int flags)
{
	int i = BUFF_SIZE - 2;
	unsigned ling int num = va_arg(types, unsigned long int);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '\0';
		buffer[BUFF_SIZE - 1] = '\0';
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - function prints unsigned integer in octal notation
 * @type: list of arguments
 * @size: the size specifier
 * @precision: precision specifier
 * @width: width specifier
 * @buffer: prints buffer arrays
 * @flags: active flags
 * return array of chars
 */
int print_octal(va_list types, char buffer[], int precision, int width, int size, int flags)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
		buffer[BUFFER_SIZE - 1] = '\0';
	}
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = '0';
		i++;
		return (write_unsgnd(0, i, flags, buffer, width, precision, size));
	}
}
/**
 * print_hexadecimal - function prints unsigned int in hexadecimal notation
 * return array of chars
 */
int print_hexadecimal(int precision, int precision int width, int size, va_list types, char buffer[])
{
       	return (print_hexa(types, buffer, flags, 'X', width, size, precsion, "0123456789ABCDEF")); 
}
/**
 * print_hexa - function prints hexa int in lower and uppercase
 * @map_to: array values to map int to
 * @flag_ch: active flags
 * returns array of char
 */
int print_hexa(char map_to[], char buffer[], va_list types, int precision, int size, int width, int glags, char flag_ch){
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	{
		buffer[i--] = '0';
		buffer[BUFFER_SIZE - 1] = '\0';
	}
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
	return (write_unsgnd(0, i, buffer, precision, flags, size, width));

}

