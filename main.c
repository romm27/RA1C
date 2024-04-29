#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {

    char line[MAX];
    int integerQuantity = 0;

    FILE *fileRead = fopen("dados.txt", "r");
    FILE *statistics = fopen("estatisticas.txt", "w");
    FILE *unique = fopen("distintos.txt", "w");
    FILE *sorted = fopen("ordernado.txt", "w");
    FILE *uniqueSorted = fopen("distintos_ordernado.txt","w");

    if (fileRead == NULL) {
        printf("Erro ao abrir o arquivo dados.txt\n");
        return 1;
    }

    if (statistics == NULL) {
        printf("Erro ao abrir o arquivo estatísticas.txt\n");
        return 1;
    }

    if (unique == NULL) {
        printf("Erro ao abrir o arquivo distintos.txt\n");
        return 1;
    }

    if (sorted == NULL) {
        printf("Erro ao abrir o arquivo ordenado.txt\n");
        return 1;
    }

    if (uniqueSorted == NULL) {
        printf("Erro ao abrir o arquivo distintos_ordenado.txt\n");
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

        int temp = 0;
        
        //Sorted
        int sortedV[index];
        memcpy(sortedV, numbers, sizeof(numbers));

        for(int i = 0; i < index; i++){
            for(int j = 0; j < index; j++){
                if(sortedV[i] < sortedV[j]){
                    temp = sortedV[i];
                    sortedV[i] = sortedV[j];
                    sortedV[j] = temp;
                }
            }
        }

        //Dados
        fprintf(statistics, "%s %d\n", "Quantidade de números positivos: ", positives);
        fprintf(statistics, "%s %d\n", "Quantidade de números negativos: ", negatives);
        fprintf(statistics, "%s %d\n", "Quantidade de números zero: ", zeros);
        fprintf(statistics, "%s %d\n", "Quantidade de números pares: ", evens);
        fprintf(statistics, "%s %d\n", "Quantidade de números ímpares: ", odds);

        //Ordenados
        for(int i = 0; i < index; i++){
            fprintf(sorted, "%d ", sortedV[i]);
        }

        // if (index > MAX) {
        //     //programa deve ser interrompido e nenhum resultado deve ser produzido
        //     return 1;

    }

    fclose(fileRead);
    fclose(statistics);
    fclose(unique);
    fclose(sorted);
    fclose(uniqueSorted);

    printf("%s", "Program successfully run!");

    return 0;
}
