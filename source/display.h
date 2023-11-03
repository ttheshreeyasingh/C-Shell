#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <string.h>
#include "../main.h"

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

void displayPrompt();


#endif
