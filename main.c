#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {

    FILE *fileRead;
    FILE *fileWrite;

    char line[MAX];
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

    //Lê a segunda linha (falta converter str para line) e a escreve no output.txt
    if (fgets(line, sizeof(line), fileRead) != NULL) {
        char str[] = "5 -2 3 4 -34"; // Falta converter a line para ser a str
        int index = 0;
        int numbers[sizeof(line)]; // O último caractere \0 está sendo contado
        char *token = strtok(str, " ");

        while (token != NULL) {
            int num = atoi(token);
            numbers[index] = num;
            index++;
            token = strtok(NULL, " ");
        }

        if (index > MAX) {
            //programa deve ser interrompido e nenhum resultado deve ser produzido
            return 0;
        }
        int i;
        for (i = 0; i < index; i++) {
            fprintf(fileWrite, "%d ", numbers[i]);
        }

        //Esta parte é apenas um teste
        int j;
        for (j = 0; j < index; j++) {
            printf("Elemento %d: %d\n", j, numbers[j]);
        }

    }

    fclose(fileRead);
    fclose(fileWrite);

    return 0;
}
