#include "main.h"
/**
 * get_size - function checks size to the argument
 * @format - formatted string that prints the argument
 * @i - param
 * return size
 */
int get_size(int *i, const char *format)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
	{
		size = S_LONG;
	}
	else if (format[curr_i] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*i = curr_i - 1;
	}
	else 
	{
		*i = curr_i;
	}
	return (size);
}
