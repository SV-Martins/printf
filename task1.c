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
        {
                printf("Error: format string is NULL.\n");
                return -1;
        }

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
			else if (*ptr == '!')
	    		{
				putchar('!');
				num_chars_printed++;
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				/* Print a decimal */
			unsigned int a, b, countnum, countP;
			int hold;

			countP = 0;
			hold = va_arg(args, int);
			if (hold < 0)
			{
				a = (hold * -1);
				countP += putchar('-');
			}
			else
			a = hold;
			b = a;
			countnum = 1;
			while (b > 9)
			{
				b /= 10;
				countnum *= 10;
			}
			while (countnum >= 1)
			{
				countP += putchar(((a / countnum) % 10) + '0');
				countnum /= 10;
			}
			num_chars_printed++;
			}
			else
			{
				/* Print any other value */
				putchar('%');
				putchar(*ptr);
				num_chars_printed += 2;
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
