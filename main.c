#include "main.h"
char *home = NULL;
int len = 0;
int main() {
    char *current_dir = getcwd(NULL, 0);
    if (home == NULL){
        len = strlen(current_dir);
        home = malloc(sizeof(char) * len);
        strcpy(home, current_dir);
    }

    printf("------------------------------------------\n"); 
    printf("\n\t     C SHELL"); 
    printf("\n\n\t-OSA Assignment 3-"); 
    printf("\n\n------------------------------------------\n\n");
    char* input = NULL;
    while(1){
        displayPrompt();
        input = readInput();
   
        char **tokens = tokenizeInput(input);
        int numoftokens = 0;
        while(tokens[numoftokens] != NULL) {
            numoftokens++;
        }
        execute(tokens, numoftokens, input);
     
        free(tokens); // Free allocated memory
        free(input);  // Free allocated memory
    }
    return 0;
}
