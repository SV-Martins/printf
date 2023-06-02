#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int main() {
    _printf("%d", 1024);
    return 0;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int value = va_arg(args, int);
    printf("%d\n", value);
    va_end(args);
    return 0;
}
