// test.h
#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define macros or helper functions for testing

#define ASSERT_EQUAL(expected, actual) \
    do { \
        if ((expected) != (actual)) { \
            fprintf(stderr, "Assertion failed: %s:%d: %s\n", __FILE__, __LINE__, #actual); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)


void  test_tokenizer();

#endif // TEST_H
