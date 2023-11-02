#include "func.h"
#include "../../main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void echo(char** tokens){
    int i = 1;
    while (tokens[i] != NULL)
    {
        printf("%s", tokens[i]);
        i++;
        if (tokens[i] != NULL)
            printf(" ");
    }
    printf("\n");
}
