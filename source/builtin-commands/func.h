#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#define RED "\033[0;31m"
#define RESET "\033[0m"

void echo(char**, char*);
void pwd();
void cd(char**);

#endif