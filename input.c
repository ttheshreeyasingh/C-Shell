#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

#define TOKEN_BUFSIZE 64

char* readInput() {
    char *input = NULL;
    size_t size = 0;
    getline(&input, &size, stdin);
    return input;
}

char** tokenizeInput(char* input) {
    char **tokens = malloc(TOKEN_BUFSIZE * sizeof(char*));
    char *token = strtok(input, " \t");
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \t");
    }
    tokens[i] = NULL;
    return tokens;
}