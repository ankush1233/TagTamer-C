#include "htmlparser.h"

struct HTMLElement* parseHTML(const char* html) {
    struct HTMLElement* htmlAccess = malloc(sizeof(struct HTMLElement));
    htmlAccess->tag = malloc(100);
    htmlAccess->content = malloc(100);
    htmlAccess->tag[0] = '\0';
    htmlAccess->content[0] = '\0';

    if (*html == '<') {
        html++;
        // Skip leading whitespaces
        while (isspace((unsigned char)*html)) {
            html++;
        }

        size_t tagLength = 0;
        while (*html != '>' && !isspace((unsigned char)*html)) {
            htmlAccess->tag[tagLength++] = *html;
            html++;
        }
        htmlAccess->tag[tagLength] = '\0';

        // Skip any remaining characters until '>'
        while (*html != '>') {
            html++;
        }
        html++;  // Move past the closing bracket

        // Skip leading whitespaces after '>'
        while (isspace((unsigned char)*html)) {
            html++;
        }

        size_t contentLength = 0;
        while (*html != '<' && *html != '\0') {
            htmlAccess->content[contentLength++] = *html;
            html++;
        }
        htmlAccess->content[contentLength] = '\0';
    }

    printf("Tag: %s\n", htmlAccess->tag);
    printf("Content: %s\n", htmlAccess->content);

    free(htmlAccess->tag);
    free(htmlAccess->content);
    free(htmlAccess);
    return htmlAccess;
}
