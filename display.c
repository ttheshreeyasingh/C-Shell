#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>

void displayPrompt() {
    char *username = getpwuid(getuid())->pw_name;
    char system_name[256];
    gethostname(system_name, sizeof(system_name));

    char current_dir[256];
    getcwd(current_dir, sizeof(current_dir));

    // Get user's home directory
    char *home_dir = getpwuid(getuid())->pw_dir;

    // Check if current_dir starts with home_dir
    if (strstr(current_dir, home_dir) == current_dir) {
        // Replace home_dir with ~
        memmove(current_dir, "~", 1);
        memmove(current_dir + 1, current_dir + strlen(home_dir), strlen(current_dir) - strlen(home_dir) + 1);
    }
    printf("------------------------------------------\n"); 
    printf("\n\t     C SHELL"); 
    printf("\n\n\t-OSA Assignment 3-"); 
    printf("\n\n------------------------------------------\n\n");
    printf("<%s@%s:%s>", username, system_name, current_dir);
}
