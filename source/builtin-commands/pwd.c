#include "func.h"
#include "../../main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void pwd(){
        char current_dir[256];
        getcwd(current_dir, sizeof(current_dir));
        printf("%s\n", current_dir);
}