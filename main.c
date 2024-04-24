#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define MAX_LENGTH 1000

int main() {

    FILE *fileRead;
    FILE *fileWrite;

    char line[MAX_LENGTH];
    int integerQuantity = 0;
    int i = 0;

    fileRead = fopen("input.txt", "r");
    fileWrite = fopen("output.txt", "w");

    if (fileRead == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //Lê a primeira linha
    if (fgets(line, sizeof(line), fileRead) != NULL) {
        integerQuantity = atoi(line);
    }

    //char numbers[MAX_LENGTH];

    //Lê a segunda linha e a escreve no output.txt
    if (fgets(line, sizeof(line), fileRead) != NULL) {
        char str[] = "5 -2 3 4 -20 4"; // Falta converter a line
        int numbers[10];
        int index = 0;

        char *token = strtok(str, " ");
        printf("%s \n", token);

        while (token != NULL) {
            int num = atoi(token);
            numbers[index] = num;
            fprintf(fileWrite, "%d ", num);
            index++;
            token = strtok(NULL, " ");
            
        }

        //Esta parte é apenas um teste
        int i;
        for (i = 0; i < index; i++) {
            printf("Elemento %d: %d\n", i, numbers[i]);
        }

    }

    fclose(fileRead);
    fclose(fileWrite);

    return 0;
}
