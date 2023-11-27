#ifndef _HTMLTOKENS_H
#define _HTMLTOKENS_H

#define CHAR_NUL '\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>


typedef enum {
    START_TAG,
    END_TAG,
    COMMENT,
    TEXT,
    HTML_EOF
} TokenType;



typedef struct {
    char* tagValue;
    bool isVoidElement;
} StartTag;



typedef struct {
    char* tagValue; 
} EndTag;



typedef struct {
    char* CommentValue; 
} Comment;



typedef struct {
    char* TextValue; 
} Text;



typedef struct {
} HtmlEOF;



typedef struct {
    TokenType type;
    void* value;
}Token;



typedef struct {
    Token* tokens;
    size_t size;
}TokenStream;



//void Display_Token();
//bool is_start_tag(const Token*, const char*);

#endif // !_HTMLTOKENS_H
