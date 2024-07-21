#ifndef HEXDUMP_PRINTER_H
#define HEXDUMP_PRINTER_H

#include <stdbool.h>

int print_line(int offset, int size, int capacity, unsigned char *data, int address_width, int base, bool abbreviate);

/**
 * Print byte in the given base on the console.
 */
int print_byte(int base, unsigned char byte);

/**
 * Print the appropriate number of spaces as a filler for a byte.
 */
int print_filler(int base);

#endif //HEXDUMP_PRINTER_H
