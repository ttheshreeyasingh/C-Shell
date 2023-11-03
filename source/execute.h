
#ifndef EXECUTE_H
#define EXECUTE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "./builtin-commands/func.h"
#include "history.h"
#define RED "\033[0;31m"
#define RESET "\033[0m"



void execute(char**, int, char*);

#endif
