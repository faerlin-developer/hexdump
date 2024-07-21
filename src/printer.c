#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "printer.h"
#include "util.h"

int print_line(int offset, int size, int capacity, unsigned char *data, int address_width, int base, bool abbreviate) {

    if (size == 0) {
        return EXIT_SUCCESS;
    }

    // Print offset in hexadecimal
    if (!abbreviate) {
        char address_format_spec[50];
        sprintf(address_format_spec, "0x%%0%dX ", address_width);
        printf(address_format_spec, offset);
    }

    // Print byte stream in the given base
    for (int i = 0; i < size; i++) {
        int err = print_byte(base, data[i]);
        if (err == EXIT_FAILURE) {
            return err;
        }
    }

    // Print spaces for proper alignment for the last row
    if (size < capacity) {
        for (int i = size; i < capacity; i++) {
            int err = print_filler(base);
            if (err == EXIT_FAILURE) {
                return err;
            }
        }
    }

    // Print ASCII representation of each byte
    // Bytes with ASCII values in the range [32, 126] are printed as is; any other characters are printed as spaces.
    if (!abbreviate) {
        printf("  ");
        const unsigned char lower = ' ';
        const unsigned char upper = '~';
        for (int i = 0; i < size; i++) {
            bool isPrintable = lower <= data[i] && data[i] <= upper;
            unsigned char ch = isPrintable ? data[i] : ' ';
            putchar(ch);
        }
    }

    putchar('\n');

    return EXIT_SUCCESS;
}

/**
 * Print byte in the given base on the console.
 */
int print_byte(int base, unsigned char byte) {

    int exit_code = EXIT_SUCCESS;
    switch (base) {
        case 2:
            char binary[9];
            binary[8] = '\0';
            byte_to_binary(byte, binary);
            printf(" %s", binary);
            break;
        case 8:
            printf(" %03o", byte);
            break;
        case 16:
            printf(" %02X", byte);
            break;
        default:
            exit_code = EXIT_FAILURE;
            break;
    }

    return exit_code;
}

/**
 * Print the appropriate number of spaces as a filler for a byte.
 */
int print_filler(int base) {

    int exit_code = EXIT_SUCCESS;
    switch (base) {
        case 2:
            printf("         ");
            break;
        case 8:
            printf("    ");
            break;
        case 16:
            printf("   ");
            break;
        default:
            exit_code = EXIT_FAILURE;
            break;
    }

    return exit_code;
}