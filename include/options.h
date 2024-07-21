#ifndef HEXDUMP_OPTIONS_H
#define HEXDUMP_OPTIONS_H

typedef struct Options Options;
struct Options {
    bool abbreviate;
    int base;
};

/**
 * Parse the option flags from the command line arguments.
 */
Options parseoptions(int argc, char *argv[]);

#endif
