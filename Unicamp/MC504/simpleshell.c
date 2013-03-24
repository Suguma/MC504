#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define max 256

char** unstring(char*, int*,int, char*);
void executar(char**, char**, int, int);

int main(int arc, char* argv[]) {
  int dirCounter = 0;
  int cmdCounter = 0;
  int i = 0;
  char** meleon = unstring(argv[1], &dirCounter, 0, ":");
  char** cmdLine = NULL;
  char* line = NULL;
  char* temp = NULL;

  //gets(temp);//command line
  temp = "whoami --version";
  line = malloc(sizeof(char)*strlen(temp));
  strcpy(line,temp);

  cmdLine = unstring(line, &cmdCounter, 1, " ");
  for(i = 0; i <= cmdCounter; i++){
    if(cmdLine[i] == NULL){
      printf("\n");
      continue;
    }
    printf("%s\n", cmdLine[i]);
  }
  executar(cmdLine, meleon, dirCounter, cmdCounter);

  for(i = 0; i < dirCounter; i++){
    printf("%s\n", meleon[i]);
  }

  return 0;
}

//Returns a string vector with all directors
char** unstring(char* str, int* counter, int extraLine, char delim[]) {
  char** mander;
  char* result;
  int i = 0;

  if(str == NULL)
    return NULL;

  //Counts number of directories in string
  *counter = 1;
  for(i = 0; i < strlen(str); i++) {
    if(str[i] == *delim)
      (*counter)++;
  }

  //Adds an extra line to the matrix
  if(extraLine){
    mander = malloc(sizeof(char)*(*counter)+1);
    mander[*counter] = 0;
  }
  else
    mander = malloc(sizeof(char)*(*counter));
  
  //Malloc for each string of the vector
  result = strtok(str,delim);
  i = 0;
  while(result != NULL && i < *counter + extraLine) {
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
  char* aux2 = NULL;
  command = malloc(sizeof(char)*strlen(cmdLine[0]));
  strcpy(command, cmdLine[0]);//tem o comando a ser executado
  for(i = 0; i < dirCounter; i++){
    aux2 = malloc(sizeof(char)*max);
    strcat(aux2, mander[i]);
    strcat(aux2, command);
    cmdLine[0] = aux2;
    printf("cmdLine: %s\n", cmdLine[0]);
    execv(aux2, cmdLine);
    printf("%s\n", aux2);
    aux2 = NULL;
    free(aux2);
  }
  free(command);
  return;
}

//comment
