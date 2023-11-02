#include "func.h"
#include "../../main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void echo(char** tokens, char* input){
        for(int i = 1; tokens[i] != NULL; i++) {
            printf("%s ", tokens[i]);            
        }
        printf("\n");
}

