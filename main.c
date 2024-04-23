#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define MAX_LENGTH 1000

int main() {

    FILE *fileRead;
    FILE *fileWrite;

    char line[MAX_LENGTH];
    char *rawInput[MAX];
    int integerQuantity = 0;

    fileRead = fopen("input.txt", "r");
    fileWrite = fopen("output.txt", "w");

    if (fileRead == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    if (fgets(line, sizeof(line), fileRead) != NULL) {
        integerQuantity = atoi(line);
    }

    if (fgets(line, sizeof(line), fileRead) != NULL) {
        printf("\n %s", line);
    }

}








    // while (fgets(line, sizeof(line), fileRead) != NULL) {

    //     // if (line[strlen(line) - 1] == '\n') {
    //     //     line[strlen(line) - 1] = '\0';
    //     // }
        
    //     rawInput[count] = malloc(strlen(line) + 1);
    //     strcpy(rawInput[count], line);
    //     fprintf(fileWrite, line);
    //     count++;

    //     if (count >= MAX) {
    //         printf("Limite máximo de linhas atingido.\n");
    //         break;
    //     }
    // }

    fclose(fileRead);
    fclose(fileWrite);

    return 0;
}
