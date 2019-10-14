#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int num_dirs, num_regular;

#define MAX_FTW_DEPTH 16

static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    // Define stuff here
    if(typeflag == FTW_F){
        num_regular++;
    }
    if(typeflag == FTW_D){
        num_dirs++;
    }
    return 0;
}

int main (int argc, char *argv[]) {
    
  num_dirs = 0;
  num_regular = 0;


  ftw(argv[1], callback, MAX_FTW_DEPTH);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}