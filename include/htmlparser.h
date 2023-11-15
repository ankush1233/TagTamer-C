#ifndef _HTMLPARSER_H
#define _HTMLPARSER_H

struct HTMLElement {
  char* tag;
  char* content;
};

typedef enum {
  START_TAG,
  END_TAG,
  COMMENT,
  TEXT,
  EOF,
}Tokens;

struct HTMLElement* parseHTML (const char*);
#endif
