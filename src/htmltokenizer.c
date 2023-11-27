#include "htmltokenizer.h"
#include "htmltokens.h"
#include "errorhandling.h"

//To tokenize the the html string to tokens
TokenStream tokenizer(const char* htmlString) {
    TokenStream tokenStream = { .tokens = NULL, .size = 0 };

    while (*htmlString != '\0') {
        // Skip whitespace
        if (isspace((unsigned char)*htmlString)) {
            htmlString++;
            continue;
        }
        //printf("check point");

		if (strncmp(htmlString, "<!--", 4) == 0) {

			htmlString += 4; // Move past <!--
	
			//Temporary buffer to store the Token type and value
            Token* newToken = (Token*)malloc(sizeof(Token));
            if (newToken == NULL) {
           		//Add the error handling mechanism
				HANDLE_ERROR("Failed to allocate memory newToken");
				exit(EXIT_FAILURE);
			}
	
			//Enter the value and the type of token
           	newToken->type = COMMENT;
           	newToken->value = (Comment*)malloc(sizeof(Comment));

			//Data Structure to store the tokens a (dynamic array) 
            tokenStream.tokens = (Token*)realloc(tokenStream.tokens, (tokenStream.size + 1) * sizeof(Token));
            if (tokenStream.tokens == NULL) {
				//Add the error handling mechanism
				HANDLE_ERROR("Failed to allocate memory tokenStream.tokens");
				exit(EXIT_FAILURE);
           	}

        	tokenStream.tokens[tokenStream.size] = *newToken;
        	//Free allocated memory which was the temporary buffer for the token
        	free(newToken);

            const char* CommentEndSign = "-->";
			//Check if the CommentEndSign is present in the htmlString
            if (strstr(htmlString, CommentEndSign) == NULL) {
            	//Add the error handing mechanism	
				HANDLE_ERROR("SubString not found");
				exit(EXIT_FAILURE);
            }

			//Get the position of the CommentEndSign
            const char* CommentEndSignPosition = strstr(htmlString, CommentEndSign);
            size_t sizeOfTheComment = CommentEndSignPosition - htmlString;

			//Temporary buffer to store the CommentBuffer because of the void* and convert the generic to the Comment*
            Comment* CommentBuffer = (Comment*)(tokenStream.tokens[tokenStream.size].value);
	
			//Allocate the size for the Comment Value
            CommentBuffer->CommentValue = (char*)malloc(sizeOfTheComment + 1);  // +1 for null terminator

			//Copy the sub string to the Comment Token
            strncpy(CommentBuffer->CommentValue, htmlString, sizeOfTheComment);
            CommentBuffer->CommentValue[sizeOfTheComment] = '\0';//null termninate it
	
            htmlString = CommentEndSignPosition + strlen(CommentEndSign);
            
			//Increase the size
			tokenStream.size++;    
		}
        else if (strncmp(htmlString, "</", 2) == 0) {
			htmlString += 2;

			Token* newToken = (Token*)malloc(sizeof(Token));

			if(newToken == NULL){
				HANDLE_ERROR("Failed to allocate memory newToken");
				exit(EXIT_FAILURE);
			}
			newToken->type = END_TAG;
			newToken->value = (EndTag*)malloc(sizeof(EndTag));

			tokenStream.tokens = (Token*)realloc(tokenStream.tokens, (tokenStream.size + 1) * sizeof(Token));
            if (tokenStream.tokens == NULL) {
				//Add the error handling mechanism
				HANDLE_ERROR("Failed to allocate memory tokenStream.tokens");
				exit(EXIT_FAILURE);
           	}

           	tokenStream.tokens[tokenStream.size] = *newToken;

           	free(newToken);
            const char* EndTagEndSign = ">";
			//Check if the EndTagEndSign is present in the htmlString
            if (strstr(htmlString, EndTagEndSign) == NULL) {
            	//Add the error handing mechanism	
				HANDLE_ERROR("SubString not found");
				exit(EXIT_FAILURE);
            }
			
			const char* EndTagEndSignPosition = strstr(htmlString, EndTagEndSign);
            size_t sizeOfTheEndTag = EndTagEndSignPosition - htmlString;

			//Temporary buffer to store the CommentBuffer because of the void* and convert the generic to the Comment*
            EndTag* EndTagBuffer = (EndTag*)(tokenStream.tokens[tokenStream.size].value);
	
			//Allocate the size for the Comment Value
            EndTagBuffer->tagValue = (char*)malloc(sizeOfTheEndTag + 1);  // +1 for null terminator

			//Copy the sub string to the Comment Token
            strncpy(EndTagBuffer->tagValue, htmlString, sizeOfTheEndTag);
            EndTagBuffer->tagValue[sizeOfTheEndTag] = '\0';//null termninate it
	
            htmlString = EndTagEndSignPosition + strlen(EndTagEndSign);
            
			//Increase the size
			tokenStream.size++; 

        }
        /*else {
        	printf("check point\n");
        	Token* newToken = (Token*)malloc(sizeof(Token));
        	if (newToken == NULL) {
				HANDLE_ERROR("Failed to allocate memory for newToken");
                exit(EXIT_FAILURE);	
        	} 

        	newToken->type = TEXT;
        	newToken->value = (Text*)malloc(sizeof(Text));

        	tokenStream.tokens = (Token*)realloc(tokenStream.tokens, (tokenStream.size + 1) * (sizeof(Token)));
            if (tokenStream.tokens == NULL) {
				//Add the error handling mechanism
				HANDLE_ERROR("Failed to allocate memory tokenStream.tokens");
				exit(EXIT_FAILURE);
           	}
			tokenStream.tokens[tokenStream.size] = *newToken;
			free(newToken);

		    // const char* textEnd = "<";
		    // const char* textEndPosition = strchr(htmlString, *textEnd);

		    // if (textEndPosition == NULL) {
		    //     // Add the error handling mechanism
		    //     HANDLE_ERROR("SubString not found");
		    //     exit(EXIT_FAILURE);
		    // }

		    // size_t sizeOfTheTextEnd = textEndPosition - htmlString;

		    // Text* textBuffer = (Text*)(tokenStream.tokens[tokenStream.size].value);
		    // textBuffer->TextValue = (char*)malloc(sizeOfTheTextEnd + 1);

		    // strncpy(textBuffer->TextValue, htmlString, sizeOfTheTextEnd);
		    // textBuffer->TextValue[sizeOfTheTextEnd] = '\0'; // Null terminate it

		    // htmlString = textEndPosition + 1; // Move past the '<' character

		    // // Increase the size
		    // tokenStream.size++;
			if (tokenStream.tokens[tokenStream.size].type == TEXT) {
			    const char* textEnd = "<";
			    const char* textEndPosition = strchr(htmlString, *textEnd);

			    if (textEndPosition == NULL) {
			        // No need to trigger an error for plain text
			        // You can handle this case differently or simply continue
			        continue;
			    }

			    size_t sizeOfTheTextEnd = textEndPosition - htmlString;

			    Text* textBuffer = (Text*)(tokenStream.tokens[tokenStream.size].value);
			    textBuffer->TextValue = (char*)malloc(sizeOfTheTextEnd + 1);

			    strncpy(textBuffer->TextValue, htmlString, sizeOfTheTextEnd);
			    textBuffer->TextValue[sizeOfTheTextEnd] = '\0'; // Null terminate it

			    htmlString = textEndPosition + 1; // Move past the '<' character

			    // Increase the size
			    tokenStream.size++;
			}

        }*/
    	htmlString++;
    }

    return tokenStream;

}
