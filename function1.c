#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // Counter for characters printed

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'
            switch (*format) {
                case 'd':
                case 'i':
                    // Integer specifier
                    {
                        int value = va_arg(args, int);
                        printf("%d", value);
                        count++;
                        break;
                    }
                default:
                    // Unsupported specifier, just print the obvious  character
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

