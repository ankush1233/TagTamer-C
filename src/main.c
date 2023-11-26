//#include "htmltokens.h"
//#include "htmltokenizer.h"
//
//int main() {
//
//    const char* htmlString = "<!--this is a comment -->";
//
//    TokenStream tokenStream = tokenizer(htmlString);
//    test_tokenizer();
//    
//    assert(tokenStream.size == 1);
//    printf("TEST CASE 1: PASSED\n");
//    
//    // Test case 2: Check the content of the first comment
//    assert(strcmp(((Comment*)tokenStream.tokens->value)->CommentValue, "this is a comment ") == 0);
//    printf("TEST CASE 2: PASSED");
//
//    // Test case 3: Check the content 
//    //assert(strcmp(((Comment*)&tokenStream.tokens[1].value)->CommentValue, " Second comment ") == 0);
//	return EXIT_SUCCESS;
//}