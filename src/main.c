#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "options.h"
#include "printer.h"
#include "util.h"
#include "io.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "usage: hexdump FILE [OPTIONS]\n");
        exit(EXIT_FAILURE);
    }

    // Parse command line arguments
    char *filename = argv[1];
    Options options = parseoptions(argc, argv);

    // Determine file size
    int filesize = (int) fsize(filename);
    if (filesize == -1) {
        fprintf(stderr, "error: unable to determine size of %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "error: unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Compute the number of digits required to represent memory offset in hexadecimal
    int address_width = numdigits(16, filesize);

    // Initialize a buffer with a pre-computed capacity determined by the chosen base.
    int capacity = (options.base == 2) ? 4 : options.base;
    unsigned char buffer[capacity];

    int err;
    int offset = 0;
    while (true) {

        int size = fget(file, capacity, buffer);
        err = print_line(offset, size, capacity, buffer, address_width, options.base, options.abbreviate);
        if (size < capacity || err == EXIT_FAILURE) {
            break;
        }

        offset += size;
    }

    fclose(file);

    return err;
}
