#include "main.h"
/**
 * get_width - function checks the width for printing
 * @format: reps formatted string that prints arguments
 * @i: param
 * @list: list of arguments
 */
int get_width(int *i, va_list list, const char *format)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = curr_i - 1;
	return (width);
}
