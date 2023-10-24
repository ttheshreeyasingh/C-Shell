#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    displayPrompt();
    char* input = NULL;
    while(1){
        input = readInput();
   
        char **tokens = tokenizeInput(input);
        int numoftokens = 0;
        while(tokens[numoftokens] != NULL) {
            numoftokens++;
        }
        // printf("Number of tokens: %d\n", numoftokens);
        execute(tokens, numoftokens);
     
        free(tokens); // Free allocated memory
        free(input);  // Free allocated memory
    }
    return 0;
}
