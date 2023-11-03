#include "../main.h"
#include "history.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int numCommandsStored = 0;

void history(int displayCount, CommandHistory storedHistory[20]) {
    for (int i = numCommandsStored - displayCount; i < numCommandsStored; i++) {
        if (i >= 0) {
            printf("%s\n", storedHistory[i].command);
        }
    }
}

void addToHistory(char* command, CommandHistory storedHistory[20]) {
    // Check for duplicate command
    if (numCommandsStored > 0 && strcmp(command, storedHistory[numCommandsStored - 1].command) == 0) {
        return;
    }

    // Add command to history
    if (numCommandsStored < 20) {
        strcpy(storedHistory[numCommandsStored].command, command);
        storedHistory[numCommandsStored].timestamp = time(NULL);
        numCommandsStored++;
    } else {
        // Overwrite oldest command
        for (int i = 0; i < 19; i++) {
            strcpy(storedHistory[i].command, storedHistory[i+1].command);
            storedHistory[i].timestamp = storedHistory[i+1].timestamp;
        }
        strcpy(storedHistory[19].command, command);
        storedHistory[19].timestamp = time(NULL);
    }
}
