#include "main.h"
/**
 * get_flags - function calculates active flags
 * @format: reps formatted stringwhich prints arguments
 * @i: parameter specifier
 * @FLAGS_CH
 * @FLAGS_ARR
 * return flags
 */
int get_flags(int *i, const char *format)
{
	int j;
	curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', ' ', '#', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_ZERO, F_HASH, F_PLUS, F_SPACE, O};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for(j = 0; FLAGS_CH[j] != '\0'; j++)
		{ 
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
			if (FLAGS_CH[j] == 0)
			{
				break;
			}
		}
	}
	*i = curr_i - 1;
	return (flags);
}
