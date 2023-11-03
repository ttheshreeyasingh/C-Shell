#include "func.h"
#include "../../main.h"

void pwd(){
        char current_dir[256];
        getcwd(current_dir, sizeof(current_dir));
        printf("%s\n", current_dir);
}