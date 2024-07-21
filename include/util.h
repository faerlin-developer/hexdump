#ifndef HEXDUMP_UTIL_H
#define HEXDUMP_UTIL_H

/**
 * Return log(a) in base b.
 */
double logbase(double b, double a);

/**
 * Return the number of digits required to express the given value in the given base.
 */
int numdigits(int base, int value);

/**
 * Get the big endian binary representation of the given byte as a string.
 */
void byte_to_binary(unsigned char byte, char binary[8]);

#endif
