#include "../main.h"
#include "./builtin-commands/func.h"
#include "history.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void execute(char** tokens, int numoftokens, char* input) {
    if(numoftokens == 0 || tokens[0] == NULL) return;
    char* command = tokens[0];
    // printf("Command is: %s\n", command);
    addToHistory(command, storedHistory);
    if(strcmp(command, "exit") == 0) exit(0);
    else if(strcmp(command, "pwd") == 0) pwd();
    else if(strcmp(command, "echo") == 0) echo(tokens, input);
    else if (strcmp(command, "cd") == 0) cd(tokens);
    else if (strcmp(command, "history") == 0) {
        int displayCount = 10; // Default display count
        int storeCount = 20;   // Default store count
        if (tokens[1] != NULL) {
            displayCount = atoi(tokens[1]);
            if (tokens[2] != NULL) {
                storeCount = atoi(tokens[2]);
            }
        }
        history(displayCount, storedHistory);
    }
}
