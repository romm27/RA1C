#include <stdio.h>

#define VECTORSIZE 1000

FILE *fileread;
FILE *filewrite;

int main(){

    fileread = fopen("input.txt", "r");
    filewrite = fopen("output.txt", "w"); 

    char input[VECTORSIZE];

    while(!feof(fileread)){
        fgets(input, VECTORSIZE, fileread);
        fprintf(filewrite, input);
        printf("%s", input);
    }

    printf("%d", sizeof(input));

    return 0;
}