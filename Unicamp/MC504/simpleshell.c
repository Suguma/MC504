#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define max 256

char** unstring(char*, int*,int, char*);
void executar(char**, char**, int, int);

int main(int arc, char* argv[]) {
  char* line;
  int dirCounter = 0, cmdCounter = 0;
  char** mander = unstring(argv[1], &dirCounter, 0, ":");
  char** cmdLine;
  int i = 0;
  
  //gets(line);//command line
  line = " whoami --version";
  cmdLine = unstring(line, &cmdCounter, 1, " ");
  executar(cmdLine, mander, dirCounter, cmdCounter);
  for(i = 0; i < 2; i++) {
    printf("%s\n", mander[i]);
  }

  return 0;
}

//Returns a string vector with all directors
char** unstring(char* str, int* dirCounter, int extraLine, char delim[]) {
  char** mander;
  char* result;
  //  char delim[] = ":";
  int i = 0;

  if(str == NULL)
    return NULL;

  //Counts number of directories in string
  *dirCounter = 1;
  for(i = 0; i < strlen(str); i++) {
    if(str[i] == *delim)
      (*dirCounter)++;
  }

  //Adds an extra line to the matrix
  if(extraLine) {
    mander = malloc(sizeof(char)*(*dirCounter)+1);
    mander[*dirCounter] = NULL;
  }
  else
    mander = malloc(sizeof(char)*(*dirCounter));
    
  
  //Malloc for each string of the vector
  result = strtok(str,delim);
  i = 0;
  while(result != NULL && i < *dirCounter + extraLine) {
    mander[i] = malloc(sizeof(char)*(strlen(result)+1));
    strcpy(mander[i],result);
    if(!extraLine)
      strcat(mander[i],"/");
    result = strtok(NULL,delim);
    i++;
  }

  return mander;
}

void executar(char** cmdLine, char** mander, int dirCounter, int cmdCounter){
  int i = 0;
  char* command = NULL;
  //char* aux;//vai testar os comandos
  printf("hastsfas\n");
  char* aux2 = NULL;
  strcpy(command, cmdLine[0]);//tem o comando a ser executado
  for(i = 0; i < dirCounter; i++){
    aux2 = malloc(sizeof(char)*max);
    strcat(aux2, mander[i]);
    strcat(aux2, command);
    printf("%s", aux2);
    free(aux2);
  }
  return;
}
