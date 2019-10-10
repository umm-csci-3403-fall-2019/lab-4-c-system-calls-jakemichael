#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "file_disemvowel.h"
#include <string.h>

#define BUF_SIZE 1024

bool is_vowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
        c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
          //return true if c is a vowel
          return true;
          }
    return false;
}

char *disemvowel_line(char *str) {

    char* newName;
    int len;
    int nameCount;
    int i;
    nameCount = 0;
    len = strlen(str);
    newName = (char*) calloc(len+1, sizeof(char));

    for (i=0; i<len; ++i) {
        if (is_vowel(str[i])){
            //do nothing
        } else {  //add consonants to new char* newName
            newName[nameCount] = str[i];
            nameCount++;
        }
    }

    newName[len] = '\0';
    return (char*) newName;
}

void disemvowel(FILE* inputFile, FILE* outputFile){
    char* buffer;
    size_t buffer_size = 100;
    char* str;

    while(getline(&buffer, &buffer_size, inputFile) > 0){
        str = disemvowel_line(buffer);
        fwrite(str, 1, strlen(str), outputFile);
        free(str);
    }
}

int main(int argc, char* argv[]){

    printf(argv[0]);
    printf("\n");
    printf(argv[1]);
    printf("\n");
    printf(argv[2]);
    printf("\n");

    FILE *inputFile;
    FILE *outputFile;

    if(argc == 1) {
        inputFile = stdin;
        outputFile = stdout;
        printf("1 argc \n");
    } else if (argc == 2) {
        printf("2 argc \n");
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
    } else {
        printf("else case");
    }

    disemvowel(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}