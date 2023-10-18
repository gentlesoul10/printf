#include "main.h"

/**
 * main - main function.
 * _printf - printf function.
 * @format: char format
 * by Olive and Mary
 * Return: printed char
 */

int _printf(const char *format, ...)
{
	int print_char = 0;
	va_list list_of_args;

	if (format == NULL)
		return (-1);

	va_start (list_of_args, format);

	while (*format)
	{
		if (*format != '%')/* code */
		{
		write(1, format, 1);
		print_char++;
		}
		else
		{
		format++;
		if (*format == '\0')
		break;
		if (*format == '%')
		{
		write(1, format, 1);
		print_char++;
		}
		else if (*format == 'c')
		{
		char c = va_arg(list_of_args, int);
		write(1, &c, 1);
		print_char++;
		}
		else if (*format == 's')
		{
		char *str = va_arg(list_of_args, char*);
		int str_len = 0;

		while (str[str_len] != '\0')
		str_len++;

		write(1, str, str_len);
		print_char += str_len;

		}
		}
		format++;
	}
	va_end(list_of_args);
	return (print_char);
}
int main (void) {
	_printf("Maria\n");
	_printf("%c\n", 'g');
	_printf("$s\n", "Mugo");
	_printf("%%\n");
	return (0);
}
