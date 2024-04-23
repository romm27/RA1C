#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

int main() {
    FILE *fileRead;
    FILE *fileWrite;

    char line[MAX_LENGTH];
    char *lines[MAX_LINES];
    int count = 0;

    fileRead = fopen("input.txt", "r");
    fileWrite = fopen("output.txt", "w");

    while (fgets(line, sizeof(line), fileRead) != NULL) {

        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        lines[count] = malloc(strlen(line) + 1);
        strcpy(lines[count], line);
        fprintf(fileWrite, line);
        count++;

        if (count >= MAX_LINES) {
            printf("Limite máximo de linhas atingido.\n");
            break;
        }
    }

    fclose(fileRead);
    fclose(fileWrite);

    return 0;
}
