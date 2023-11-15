#include <stdio.h>
#include "main.h"

// Function to print binary representation of an unsigned integer
void print_binary(unsigned int num) {
    if (num > 1) {
        print_binary(num >> 1); // Recursively print the binary representation
    }
    putchar((num & 1) ? '1' : '0'); // Printing the least significant bit
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // Counter for characters printed in process

    while (*format) {
        if (*format == '%') {
            format++; // Move past this '%'
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
                case 'b':
                    // Custom binary specifier
                    {
                        unsigned int bin_value = va_arg(args, unsigned int);
                        print_binary(bin_value);
                        count++;
                        break;
                    }
                default:
                    // Unsupported specifier, just print the character
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

