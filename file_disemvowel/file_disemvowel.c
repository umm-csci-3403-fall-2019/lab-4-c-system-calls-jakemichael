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
    char *buffer = NULL;
    size_t buffer_size = 100;
    char* str;

    while(getline(&buffer, &buffer_size, inputFile) != -1){
        str = disemvowel_line(buffer);
        fwrite(str, 1, strlen(str), outputFile);
        free(str);
    }

    free(buffer);
}

int main(int argc, char* argv[]){

    FILE *inputFile;
    FILE *outputFile;

    if(argc == 1) {
        inputFile = stdin;
        outputFile = stdout;
    } else if (argc == 2) {
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
    } else if (argc == 3){
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    } else {
        printf("oof"); //should be handled better than this
    }

    disemvowel(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}