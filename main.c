#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define MAX_LENGTH 1000

int main() {

    FILE *fileRead;
    FILE *fileWrite;

    char line[MAX_LENGTH];
    //char *rawInput[MAX];
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

    char numbers[MAX_LENGTH];

    if (fgets(line, sizeof(line), fileRead) != NULL) {
        numbers = line;
    }




    printf("\n %s", numbers);

    // char str[] = "1 -2 3 4 -20 4";
    // int numeros[10];
    // int indice = 0;

    // char *token = strtok(numbers, " ");

    // while (token != NULL) {
    //     int num = atoi(token);
    //     numeros[indice] = num;
    //     indice++;
    //     token = strtok(NULL, " ");
    // }

    // int i;
    // for (i = 0; i < indice; i++) {
    //     printf("Elemento %d: %d\n", i, numeros[i]);
    // }
    fclose(fileRead);
    fclose(fileWrite);

    return 0;
}
