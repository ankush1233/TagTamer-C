// test.c
/*
#include "htmltokens.h"
#include "htmltokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_tokenizer() {
    const char* htmlString = "<!--this is a comment -->";

    TokenStream tokenStream = tokenizer(htmlString);

    // Test case 1: Check the content of the first comment
    assert(strcmp(((Comment*)tokenStream.tokens->value)->CommentValue, "this is a comment ") == 0);
    printf("TEST CASE 1: PASSED\n");

    // Free allocated memory
    free(((Comment*)((tokenStream.tokens)->value))->CommentValue);
    free((Comment*)((tokenStream.tokens)->value));
    free(tokenStream.tokens);
}
*/
// No main function in a testing file

// test.c
#include "htmltokens.h"
#include "htmltokenizer.h"
#include "test.h"

void test_tokenizer() {
    const char* htmlString = "<!--this is a comment --> andffs <!-- danmn man-->";

    TokenStream tokenStream = tokenizer(htmlString);

    Comment* CommentBuffer = (Comment*)malloc(tokenStream.size * sizeof(Comment));
    CommentBuffer = (tokenStream.tokens[0].value);

    // Use assertions or other testing mechanisms
    ASSERT_EQUAL(strcmp(CommentBuffer->CommentValue, "this is a comment "), 0);
    CommentBuffer = (tokenStream.tokens[1].value);
    
    ASSERT_EQUAL(strcmp(CommentBuffer->CommentValue, " danmn man"), 0);
    ASSERT_EQUAL(tokenStream.size, 2);

    // Free allocated memory
    free(CommentBuffer);
    free(((Comment*)((tokenStream.tokens)->value))->CommentValue);
    free((Comment*)((tokenStream.tokens)->value));
    free(tokenStream.tokens);
}

int main() {
    // Call your test functions
    test_tokenizer();

    // Other test functions can be called here

    printf("ALL TESTS PASSED !!!\n");
    return EXIT_SUCCESS;
}
