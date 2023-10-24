#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    displayPrompt();
    char* input = readInput();
    // printf("%s", input);
    char **tokens = tokenizeInput(input);
    // printf("%s\n", tokens[0]);
    return 0;
}
