#include "func.h"
#include "../../main.h"

void echo(char** tokens, char* input){
        for(int i = 1; tokens[i] != NULL; i++) {
            printf("%s ", tokens[i]);            
        }
        printf("\n");
}

