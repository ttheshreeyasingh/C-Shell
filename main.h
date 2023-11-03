#ifndef MAIN_H
#define MAIN_H
#define TOKEN_BUFSIZE 64
void displayPrompt();
char* readInput();
char** tokenizeInput(char*);
void execute(char**, int, char*);

#endif
