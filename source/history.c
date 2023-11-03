#include "history.h"

int numCommandsStored = 0;

void saveHistoryToFile(CommandHistory storedHistory[20]) {
    FILE* file = fopen("history.txt", "w");
    if (file == NULL) {
        perror("Error opening history file");
        return;
    }

    for (int i = 0; i < numCommandsStored; i++) {
        fprintf(file, "%s\n", storedHistory[i].command);
    }

    fclose(file);
}

void loadHistoryFromFile(CommandHistory storedHistory[20]) {
    FILE* file = fopen("history.txt", "r");
    if (file == NULL) {
        // File doesn't exist, create it
        file = fopen("history.txt", "w");
        if (file == NULL) {
            perror("Error creating history file");
            return;
        }
        fclose(file);
        return;
    }

    numCommandsStored = 0;
    while (fscanf(file, "%255s\n", storedHistory[numCommandsStored].command) == 1) {
        numCommandsStored++;
    }

    fclose(file);
}


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
