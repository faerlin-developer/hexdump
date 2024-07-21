#ifndef HEXDUMP_IO_H
#define HEXDUMP_IO_H

#include <stdio.h>

/**
 * Return the size of the given file in bytes.
 */
long fsize(char *filename);

/**
 * Reads data from the given file into a specified buffer. Return the number of actual elements read.
 */
int fget(FILE *file, int capacity, unsigned char buffer[capacity]);

#endif
