#ifndef _ERROR_HANDLING_H
#define _ERROR_HANDLING_H

#include <stdio.h>

#define HANDLE_ERROR(msg) do { \
    fprintf(stderr, "ERROR: %s\n", msg); \
} while (0)

#endif

