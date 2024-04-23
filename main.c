#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTORMAXSIZE 1000

FILE *fileread;
FILE *filewrite;

int main(){

    fileread = fopen("rawInput.txt", "r");
    filewrite = fopen("output.txt", "w"); 

    char rawInput[VECTORMAXSIZE];

    int lineCount  = 0;
    while(!feof(fileread)){
        fgets(rawInput, VECTORMAXSIZE, fileread);
        fprintf(filewrite, rawInput);
        printf("%s", rawInput);
        lineCount++;
    }

    int input[lineCount];

    for(int i = 0; i < lineCount; i++){
        char temp[sizeof(rawInput[i])] = rawInput[i];
        input[i] = atoi(temp);
        printf("%d\n", input[i]);
    }

    //printf("%d", sizeof(rawInput));
    printf("%d", lineCount);

    return 0;
}