#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>
extern char *home;
extern int len;
void displayPrompt();
char* readInput();
char** tokenizeInput(char*);
void execute(char**, int, char*);

#endif
