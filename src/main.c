#include "htmltokens.h"
#include "htmltokenizer.h"

int main() {

    const char* htmlString = "<!-- First comment -->";

    TokenStream tokenStream = tokenizer(htmlString);

    //printf("Comment:%s\n", ((Comment*)(tokenStream.tokens->value))->CommentValue);
    //for (size_t i = 0; i < tokenStream.size; i++) {
        if ((tokenStream.tokens)->type == COMMENT) {
            printf("Comment:%s\n", ((Comment*)(tokenStream.tokens->value))->CommentValue);
            //free(((Comment*)&tokenStream.tokens[i].value)->CommentValue);
        }
    //}

    //assert(tokenStream.size == 2);

    // Test case 2: Check the content of the first comment
    assert(strcmp(((Comment*)tokenStream.tokens->value)->CommentValue, " First comment ") == 0);

    // Test case 3: Check the content 
    //assert(strcmp(((Comment*)&tokenStream.tokens[1].value)->CommentValue, " Second comment ") == 0);
	return 0;
}