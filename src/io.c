#include <stdio.h>
#include <stdlib.h>
#include "io.h"

/**
 * Return the size of the given file in bytes.
 */
long fsize(char *filename) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "error: %s not found\n", filename);
        return -1;
    }

    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
}

/**
 * Reads data from the given file into a specified buffer. Return the number of actual elements read.
 */
int fget(FILE *file, int capacity, unsigned char buffer[capacity]) {

    int ch;
    int index = 0;
    while (index < capacity) {
        ch = fgetc(file);
        if (ch == EOF) {
            break;
        }

        buffer[index] = (unsigned char) ch;
        index++;
    }

    return index;
}