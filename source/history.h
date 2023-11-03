#ifndef HISTORY_H
#define HISTORY_H
#include <time.h>
// Define a structure to hold command history
typedef struct CommandHistory {
    char command[256];
    time_t timestamp;
}CommandHistory;

CommandHistory storedHistory[20]; // Array to store history
extern int numCommandsStored; // Counter for stored commands

void history(int, CommandHistory[20]);
void addToHistory(char*, CommandHistory[20]);

#endif
