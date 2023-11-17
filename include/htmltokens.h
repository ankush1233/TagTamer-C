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
    TokenType type;
    char* tag;
    bool isVoidElements;
} StartTag;

typedef struct {
    TokenType type;
    char* tag; 
    bool isVoidElements;
} EndTag;

typedef struct {
    TokenType type;
    char* CommentValue; 
} Comment;

typedef struct {
    TokenType type;
    char* TextValue; 
} Text;

typedef struct {
    TokenType type;
} HtmlEOF;

typedef struct {
    TokenType type;
    char* value;
}Token;



#endif // !_HTMLTOKENS_H
