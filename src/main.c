#include "htmlparser.h"

int main() {
	const char* html = "<html> Hello from html </html>";
	assert(parseHTML(html) != NULL);
	
	return 0;
}