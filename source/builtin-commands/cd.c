#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>

#define RED "\033[0;31m"
#define RESET "\033[0m"

void cd(char** tokens) {
    static char prev_dir[256]; // Static variable to store previous directory

    if (tokens[1] == NULL) {
        // No arguments provided, go to home directory
        char* home_dir = getpwuid(getuid())->pw_dir;
        strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        chdir(home_dir);
    } else if (strcmp(tokens[1], "..") == 0) {
        // Move up one level in the directory hierarchy
        strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        chdir("..");
    } else if (strcmp(tokens[1], "-") == 0) {
        // Move to the previous directory
        if (prev_dir[0] != '\0') {
            printf("%s\n", prev_dir);
            chdir(prev_dir);
        } else {
            printf(RED "No previous directory stored.\n" RESET);
        }
    } else if (strcmp(tokens[1], "~") == 0) {
        // Go to home directory
        char* home_dir = getpwuid(getuid())->pw_dir;
        strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        chdir(home_dir);
    } else if(tokens[2] == NULL){
        // Attempt to change to the specified directory
        if (chdir(tokens[1]) != 0) {
            printf(RED "cd: %s: No such file or directory\n" RESET, tokens[1]);
        } else {
            strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        }
    } else {
        printf(RED "cd: too many arguments\n" RESET);
    }
}

