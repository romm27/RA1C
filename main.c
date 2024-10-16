#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000
#define INPUT_SIZE index

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

        for(int i = 0; i < index; i++){
            sortedV[i] = numbers[i];
        }

        for(int i = 0; i < index; i++){
            for(int j = 0; j < index; j++){
                if(sortedV[i] < sortedV[j]){
                    temp = sortedV[i];
                    sortedV[i] = sortedV[j];
                    sortedV[j] = temp;
                }
            }
        }

        //Sorted Dist
        int sortedDistV[index];
        sortedDistV[0] = sortedV[0];
        int lastN = sortedV[0];
        int indexSortedDist = 1;
        for(int i = 1; i < index; i++){
            if(sortedV[i] != lastN){
                sortedDistV[indexSortedDist] = sortedV[i];
                indexSortedDist++;
            }
            lastN = sortedV[i];
        }

        //Dist
        int distV[indexSortedDist];
        bool checkList[indexSortedDist];
        int indexDist = 0;

        for(int i = 0; i < indexSortedDist; i++){
            checkList[i] = false;
        }

        //printf("count: %d %d \n", index, indexSortedDist);
        for(int i = 0; i < index; i++){
            for(int j = 0; j < indexSortedDist; j++){
                if(numbers[i] == sortedDistV[j] && checkList[j] == false){
                    distV[indexDist] = numbers[i];
                    checkList[j] = true;
                    indexDist++;
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

        //Distinto Ordenados
        for(int i = 0; i < indexSortedDist; i++){
            fprintf(uniqueSorted, "%d ", sortedDistV[i]);
        }

        //Distintos
        for(int i = 0; i < indexDist; i++){
            fprintf(unique, "%d ", distV[i]);
        }
   return 1;

    }

    fclose(fileRead);
    fclose(statistics);
    fclose(unique);
    fclose(sorted);
    fclose(uniqueSorted);

    printf("%s", "Programa executado com sucesso!");

    return 0;
}
