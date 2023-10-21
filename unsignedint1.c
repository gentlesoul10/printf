#include "main.h"
/**
 * comments will list all functions and var in this file
 * print_pointer - function prints ponter var
 * print_non_printable - function prints ascii codes of hexa non-printable notations
 * print_reverse - function prints string in reverse
 * print_rot13string - functio prints astring in rot13
 * @types: lists arguments
 * @size: size specifier
 * @precision: precision specifier
 * @buffer: prints array buffer
 * @width: width specifier
 * @flags -active flags
 * return printed char string
 */
int print_pointer(int width, int flags, int precision, int size, char buffer[], va_list types)
{
	char extra_c = 0, pad = '0';
	int ind = BUFF_SIZE - 2, length = 2, padd_start =1;
	/*the length is 2 for '0x'*/
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);
	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
	{
		return (write(1, "(nil)", 5));
		buffer[BUFFER_SIZE - 1] = '\0';
		UNUSED(precision);
		num_addrs = (unsigned long)addrs;
	}
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		padd = '0';
		if (flags & F_PLUS)
		{
			extra_c = '+', length++;
		}
	}
	else if (flags & F_SPACE)
	{
		extra_c = ' ', length++;
		ind++;
		return(write_pointer(width, padd, extra_c, padd_start, length, ind, buffer));
	}
}
/*new function to print ascii codes*/
int print_non_printable(int width, int precision, int size, int flags, char buffer[], va_list types)
{
	int i = 0;
	offset = 0;
	char *str = va_arg(types, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

if (str == NULL)
{
	return (write(1, "(null)", 6));
}
while (str[i] != '\0')
{
	if (is_printable(str[i]))
	{
		buffer[i + offset] = str[i];
	}
	else
		offset += append_hexa_code(str[i], buffer, i + offset);
	i++;
}
buffer[i + offset] = '\0';
return (write(1, buffer, i + offset));
}
/*new function that prints reverse string*/
int print_reverse(int width, int precision, int size, int flags, char buffer[], va_list types)
{
	char *str;
	int i = 0;
	count = 0;
	UNUSED(buffer, width, flags, size);
	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (i = 0, str[i]; i++)
	{
		for (i = i - 1; i >= 0; i--)
		{
			char z = str[i];
			write(1, &z, 1);
			count++;
		}
		return (count);
	}
}
/*new function that prints a string in ROT13*/
int print_rot13string(int presicion, int flags, int width, int size, char buffer[], va_list types)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "MNOPQRSTUVWXYZABCDEFGHIJKLmnopqrstuvwxyzabcdefghijkl";
	str = va_arg(types, char *);
	UNUSED(buffer, flags, precision, size, width);

	if (str == NULL)
	{
		str = "(AHYY)";
		for (i = 0; str[i]; i++)
		{
			for (j = 0; in[j]; j++)
			{
				if (in[j] == str[i])
				{
					x = out[j];
					write(1, &x, 1);
					count++;
					break;
				}
			}
			if (!in[j])
			{
				x = str[i];
				write(1, &x, 1);
				count ++;
			}
		}
		return (count);
	}
}
