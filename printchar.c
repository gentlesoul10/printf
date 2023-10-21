#include "main.h"
/**
 *_printf - function output in a format
 *@format: param character string
 *Return char string
 */
int _printf(const char *format, ...)
{
	int m;
	printed = 0;
	printed_chars = 0;
	int flags = 0;
	int width = 0;
	int precision = 0; 
	int size = 0;
	int buff_int = 0;
	va_list list;
	char_buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				/*loop prints (1, &format[i], i)*/
				printed_chars++;
			}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flags, width, precision, size);

			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printedl
		}
		}
		print_buffer(buffer, &buff_ind);
		va_end(list);
		return (printed_chars);
	}
/**
 * print_buffer - function prints contents of the buffer if it exists
 * @buffer: param array of chars
 * @buff_ind:the index at which the next char is added
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}

}
