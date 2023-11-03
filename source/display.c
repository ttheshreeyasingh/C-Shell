#include "display.h"

void format_directory(char **directory){
    if (strlen(*directory) < len){
        return;
    }

    else{
        for (int i = 0; i < len; i++){
            if (home[i] != (*directory)[i]){
                return;
            }
        }
    }

    *(*directory + len - 1) = '~';
    *directory = *directory + len - 1;
}

void displayPrompt() {
    
    char *username = getpwuid(getuid())->pw_name;
    char system_name[256];
    gethostname(system_name, sizeof(system_name));
    char *current_dir = getcwd(NULL, 0);
    format_directory(&current_dir);

    // char current_dir[256];
    // getcwd(current_dir, sizeof(current_dir));

    // // Get user's home directory
    // char *home_dir = getpwuid(getuid())->pw_dir;

    // // Check if current_dir starts with home_dir
    // if (strstr(current_dir, home_dir) == current_dir) {
    //     // Replace home_dir with ~
    //     memmove(current_dir, "~", 1);
    //     memmove(current_dir + 1, current_dir + strlen(home_dir), strlen(current_dir) - strlen(home_dir) + 1);
    // }
   
    printf("<" CYAN "%s" RESET "@" YELLOW "%s" RESET ":" GREEN"%s" RESET ">" , username, system_name, current_dir);
}

