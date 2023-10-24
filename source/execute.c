#include "../main.h"
#include "./builtin-commands/func.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void execute(char** tokens, int numoftokens) {
    if(numoftokens == 0 || tokens[0] == NULL) return;
    char* command = tokens[0];
    // printf("Command is: %s\n", command);

    if(strcmp(command, "exit") == 0) exit(0);
    else if(strcmp(command, "pwd") == 0) pwd();
    else if(strcmp(command, "echo") == 0) echo(tokens);
}
