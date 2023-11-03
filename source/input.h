#ifndef INPUT_H
#define INPUT_H
#define TOKEN_BUFSIZE 64
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void trim(char*);
char* readInput();
char** tokenizeInput(char*);

#endif
