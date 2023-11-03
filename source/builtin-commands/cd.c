#include "func.h"
#include "../../main.h"

void cd(char** tokens) {
    static char prev_dir[256]; // Static variable to store previous directory

    if (tokens[1] == NULL) {
        // No arguments provided, go to home directory
        // char* home_dir = getpwuid(getuid())->pw_dir;
        strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        chdir(home);
    } else if (strcmp(tokens[1], "..") == 0) {
        // Move up one level in the directory hierarchy
        strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        chdir("..");
    }  else if (strcmp(tokens[1], ".") == 0) {
        strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        ; // Do nothing
    }  else if (strcmp(tokens[1], "-") == 0) {
        // Move to the previous directory
        if (prev_dir[0] != '\0') {
            printf("%s\n", prev_dir);
            chdir(prev_dir);
        } else {
            perror(RED "No previous directory stored.\n" RESET);
        }
    } else if (strcmp(tokens[1], "~") == 0) {
        // Go to home directory
        // char* home_dir = getpwuid(getuid())->pw_dir;
        strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        chdir(home);
    } else if(tokens[2] == NULL){
        // Attempt to change to the specified directory
        if (chdir(tokens[1]) != 0) {
            perror(RED "cd: No such file or directory\n" RESET);
        } else {
            strcpy(prev_dir, getcwd(NULL, 0)); // Store current directory
        }
    } else {
        perror(RED "cd: too many arguments\n" RESET);
    }
}

