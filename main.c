#include <stdio.h>

#define VECTORSIZE 1000

FILE *file;

int main(){
    file = fopen("input.txt", "r");

    char input[VECTORSIZE];

    while(!feof(file)){
        fgets(input, VECTORSIZE, file);
    }

    printf("%s", input);

    return 0;
}