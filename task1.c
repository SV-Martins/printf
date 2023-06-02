#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - handling conversions
 * @format: character holding the value
 * Return: value (success)
 */
int _printf(const char *format, ...)
{
	int num_chars_printed = 0;
	const char *ptr = format;
	va_list args;
	va_start(args, format);

	if (format == NULL)
        return 0;
	
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				/* Print a single character*/
				char c = (char)va_arg(args, int);
				putchar(c);
				num_chars_printed++;
			}
			else if (*ptr == 's')
			{
				/* Print a string*/
				 char *str = va_arg(args, char *);
				 if (str == NULL)
					str = "(null)";
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					num_chars_printed++;
				}
			}
			else if (*ptr == '%')
			{
				/* Print a literal '%' */
				putchar('%');
				num_chars_printed++;
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				/* Print an integer*/
				int value = va_arg(args, int);
				printf("%d", value);
				num_chars_printed++;
			}
			else
			{
				/* Print any other value */
				putchar('%');
				putchar(*ptr);
				num_chars_printed++;
			}
		}
		else
		{
			/* Print any non-format specifier characters*/
			putchar(*ptr);
			num_chars_printed++;
		}
		ptr++;
	}
	va_end(args);
	
	return num_chars_printed;
}
