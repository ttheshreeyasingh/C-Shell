#include "input.h"

void trim(char* str) {
    int start = 0, end = strlen(str) - 1;

    while (isspace(str[start])) {
        start++;
    }

    while (end > start && isspace(str[end])) {
        end--;
    }
    int i, j;
    for ( i = start, j = 0; i <= end; i++, j++) 
        str[j] = str[i];
    
    str[j] = '\0';
}

char** tokenizeInput(char* input) {
    char **tokens = malloc(TOKEN_BUFSIZE * sizeof(char*));
    char *token = strtok(input, " \t");
    int i = 0;
    while (token != NULL) {
        trim(token); 
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \t");
    }
    tokens[i] = NULL;
    return tokens;
}

char* readInput() {
    char *input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    return input;
}
