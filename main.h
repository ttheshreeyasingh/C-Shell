#ifndef MAIN_H
#define MAIN_H

void displayPrompt();
char* readInput();
char** tokenizeInput(char* input);
void execute(char** tokens, int numoftokens);

#endif
