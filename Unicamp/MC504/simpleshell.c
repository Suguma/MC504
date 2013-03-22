#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** unstring(char* argv[], int*,int);

int main(int arc, char* argv[]) {
  int dirCounter = 0;
  char** mander = unstring(argv,&dirCounter,0);
  int i = 0;
  int j = 0;
  
  for(i = 0; i < 2; i++) {
    printf("%s\n", mander[i]);
  }

  return 0;
}

//Returns a string vector with all directors
char** unstring(char* argv[], int* dirCounter, int extraLine) {
  char** mander;
  char* result;
  char delim[] = ":";
  int i = 0;

  if(argv[1] == NULL)
    return NULL;

  //Counts number of directories in string
  *dirCounter = 1;
  for(i = 0; i < strlen(argv[1]); i++) {
    if(argv[1][i] == ':')
      (*dirCounter)++;
  }

  //Adds an extra line to the matrix
  if(extraLine) {
    mander = malloc(sizeof(char)*(*dirCounter)+1);
    mander[*dirCounter + 1] = NULL;
  }
  else
    mander = malloc(sizeof(char)*(*dirCounter));
    
  
  //Malloc for each string of the vector
  result = strtok(argv[1],delim);
  i = 0;
  while(result != NULL && i < *dirCounter) {
    mander[i] = malloc(sizeof(char)*(strlen(result)+1));
    strcpy(mander[i],result);
    strcat(mander[i],"/");
    result = strtok(NULL,delim);
    i++;
  }

  return mander;
}
