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

    fileRead = fopen("dados.txt", "r");
    fileWrite = fopen("output.txt", "w");

    FILE *statistics = fopen("estatisticas.txt", "w");
    FILE *unique = fopen("distintos.txt", "w");
    FILE *sorted = fopen("ordernado.txt", "w");
    FILE *uniqueSorted = fopen("distintos_ordernado.txt","w");

    if (fileRead == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //Lê a primeira linha
    if (fgets(line, sizeof(line), fileRead) != NULL) {
        integerQuantity = atoi(line);
    }

    //Lê a segunda linha
    if (fgets(line, sizeof(line), fileRead) != NULL) {
        int index = 0;
        int numbers[sizeof(line)];
        char *token = strtok(line, " ");

        while (token != NULL) {
            int num = atoi(token);
            numbers[index] = num;
            index++;
            token = strtok(NULL, " ");
        }

        // Faz verificações necessárias e escreve no arquivo estatisticas.txt
        int count = 0;
        int zeros = 0;
        int positives = 0;
        int negatives = 0;
        int evens = 0;
        int odds = 0;

        while (count < index) {
            if (numbers[count] == 0) {
                zeros += 1;
            } 
            
            if (numbers[count] < 0) {
                negatives += 1;
            }
            
            if (numbers[count] > 0) {
                positives += 1;
            }

            if (numbers[count] % 2 == 0) {
                evens += 1;
            }

            if (numbers[count] % 2 != 0) {
                odds += 1;
            }

            count++;
        }

        fprintf(statistics, "%s %d\n", "Quantidade de numeros positivos: ", positives);
        fprintf(statistics, "%s %d\n", "Quantidade de numeros negativos: ", negatives);
        fprintf(statistics, "%s %d\n", "Quantidade de numeros zero: ", zeros);
        fprintf(statistics, "%s %d\n", "Quantidade de numeros pares: ", evens);
        fprintf(statistics, "%s %d\n", "Quantidade de numeros ímpares: ", odds);

        // if (index > MAX) {
        //     //programa deve ser interrompido e nenhum resultado deve ser produzido
        //     return 1;

    }

    fclose(fileRead);
    fclose(fileWrite);

    return 0;
}
