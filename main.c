#include <stdio.h>
#include <limits.h>
#include "main.h"
/**
 * main - Entyr point
 * Return - Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;
	len = _printf("Print a simple sentence.\n");
	len2 = printf("Print a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unisgned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unisigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_pritntf("String:[%s]\n", "This is a string!");
	printf("String:[%s]\n", "This is a string!");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len2:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
