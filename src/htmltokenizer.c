#include "htmltokenizer.h"
#include "htmltokens.h"

TokenStream tokenizer(const char* htmlString) {
    TokenStream tokenStream = { .tokens = NULL, .size = 0 };

    while (*htmlString != '\0') {
        // Skip whitespace
        if (isspace((unsigned char)*htmlString)) {
            htmlString++;
            continue;
        }
        // Check for the start of a comment
        if (strncmp(htmlString, "<!--", 4) == 0) {
            
            htmlString += 4; // Move past <!--

            tokenStream.tokens = (Token*)malloc(sizeof(Token));

            if (tokenStream.tokens == NULL) {
                exit(EXIT_FAILURE);
            }

            (tokenStream.tokens)->type = COMMENT;
            (tokenStream.tokens)->value = (Comment*)malloc(sizeof(Comment));

            ((Comment*)((tokenStream.tokens)->value))->CommentValue = (char*)malloc(sizeof(char));
            
            const char* CommentEndSign = "-->";

            if (strstr(htmlString, CommentEndSign) == NULL) {
                exit(EXIT_FAILURE);
            }
            
            const char* CommentEndSignPosition = strstr(htmlString, CommentEndSign);
            //size_t sizeOfTheComment = CommentEndSign - htmlString;

            size_t sizeOfTheComment = CommentEndSignPosition - htmlString;

            strncpy(((Comment*)(tokenStream.tokens->value))->CommentValue, htmlString, sizeOfTheComment);

        }
        else {
            // If it's not the start of a comment, move to the next character
            htmlString++;
        }
    }

    return tokenStream;
}
