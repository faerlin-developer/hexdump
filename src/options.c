#include <getopt.h>
#include <stdbool.h>
#include "options.h"

/**
 * Parse the option flags from the command line arguments.
 */
Options parseoptions(int argc, char *argv[]) {

    Options options = {.abbreviate = false, .base = 16};

    int option = 0;
    while ((option = getopt(argc, argv, "aboh")) != -1) {

        switch (option) {
            case 'a':
                options.abbreviate = true;
                break;
            case 'h':
                options.base = 16;
                break;
            case 'o':
                options.base = 8;
                break;
            case 'b':
                options.base = 2;
                break;
            case '?':
                break;
        }
    }

    return options;
}