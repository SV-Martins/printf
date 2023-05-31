#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int num_chars_printed = 0;
    const char *ptr = format;

    while (*ptr != '\0')
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
            {
                // Print a single character
                char c = (char)va_arg(args, int);
                putchar(c);
                num_chars_printed++;
            }
            else if (*ptr == 's')
            {
                // Print a string
                const char *str = va_arg(args, const char *);
                while (*str != '\0')
                {
                    putchar(*str);
                    str++;
                    num_chars_printed++;
                }
            }
            else if (*ptr == '%')
            {
                // Print a literal '%'
                putchar('%');
                num_chars_printed++;
            }
        }
        else
        {
            // Print any non-format specifier characters
            putchar(*ptr);
            num_chars_printed++;
        }

        ptr++;
    }

    va_end(args);

    return num_chars_printed;
}
