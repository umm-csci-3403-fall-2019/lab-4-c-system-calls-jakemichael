#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "file_disemvowel.h"
#include <string.h>

#define BUF_SIZE 1024

char *disemvowel(char *str) {

   char* newName;
   int len;
   int nameCount;
   int i;
   nameCount = 0;
   len = strlen(str);
   newName = (char*) calloc(len+1, sizeof(char));


   for (i=0; i<len; ++i) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
       c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
      {
      //do nothing
      }
      //add consonants to new char* newName
      else{bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
      newName[nameCount] = c;
      nameCount++;
      }
   }

   newName[len] = '\0';

  return (char*) newName;
}
bool is_vowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
           c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
          {
          //return true if c is a vowel
          return true;
          }
    return false;
}
int copy_non_vowels(int num_chars, char* in_buf, char* out,buf){
    if(is_vowel == false){

    }
    }
}
void disemvowel(FILE* inputFile, FILE* outputFile){
      char* buffer;
      size_t buffer_size = 100;
      char* str;

      while(getline(&buffer, &buffer_size, stdin) > 0){
          str = disemvowel(buffer);
          fwrite(str, strln(str), sizeof(str), outputFile);
      }

}
int main(int argc, char* argv[]){

    FILE *inputFile;
    FILE *outputFile;

    disemvowel(inputFile, outputFile);

    return 0;
}