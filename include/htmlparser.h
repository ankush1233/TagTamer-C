#ifndef _HTMLPARSER_H
#define _HTMLPARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

struct HTMLElement {
  char* tag;
  char* content;
};

typedef enum {
  START_TAG,
  END_TAG,
  COMMENT,
  TEXT,
  HTML_EOF
}Tokens;



struct HTMLElement* parseHTML (const char*);
#endif
