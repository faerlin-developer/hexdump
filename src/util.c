#include <stdio.h>
#include <math.h>
#include "util.h"

/**
 * Return log(a) in base b.
 */
double logbase(double b, double a) {
    return log(a) / log(b);
}

/**
 * Return the number of digits required to express the given value in the given base.
 */
int numdigits(int base, int value) {
    return (int) (floorl(logbase(base, value)) + 1);
}

/**
 * Get the big endian binary representation of the given byte as a string.
 */
void byte_to_binary(unsigned char byte, char binary[8]) {

    for (int i = 0; i < 8; i++) {
        binary[i] = '0';
    }

    unsigned char mask = 1;
    for (int i = 7; i >= 0; i--) {
        if ((byte & mask) != 0) {
            binary[i] = '1';
        }
        mask = (unsigned char) (mask << 1);
    }
}