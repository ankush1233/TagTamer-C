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
        if (*htmlString == '<') {
            if (strncmp(htmlString, "<!--", 4) == 0) {

                htmlString += 4; // Move past <!--

                Token* newToken = (Token*)malloc(sizeof(Token));
                if (newToken == NULL) {
                    exit(EXIT_FAILURE);
                }

                newToken->type = COMMENT;
                newToken->value = (Comment*)malloc(sizeof(Comment));

                tokenStream.tokens = (Token*)realloc(tokenStream.tokens, (tokenStream.size + 1) * sizeof(Token));
                if (tokenStream.tokens == NULL) {
                    exit(EXIT_FAILURE);
                }

                tokenStream.tokens[tokenStream.size] = *newToken;
                //tokenStream.tokens = newToken;
                free(newToken);

                const char* CommentEndSign = "-->";

                if (strstr(htmlString, CommentEndSign) == NULL) {
                    exit(EXIT_FAILURE);
                }

                const char* CommentEndSignPosition = strstr(htmlString, CommentEndSign);
                size_t sizeOfTheComment = CommentEndSignPosition - htmlString;

                Comment* CommentBuffer = (tokenStream.tokens[tokenStream.size].value);

                CommentBuffer->CommentValue = (char*)malloc(sizeOfTheComment + 1);  // +1 for null terminator

                strncpy(CommentBuffer->CommentValue, htmlString, sizeOfTheComment);
                CommentBuffer->CommentValue[sizeOfTheComment] = '\0';

                htmlString = CommentEndSignPosition + strlen(CommentEndSign);
                tokenStream.size++;
            }
            else {
                // If it's not the start of a comment, move to the next character
                htmlString++;
            }
        }
        else {
            htmlString++;
        }
    }

    return tokenStream;

}
