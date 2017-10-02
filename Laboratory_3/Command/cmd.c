#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.c"
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h> 


#define _POSIX_SOURCE
#define TAM 100
#undef _POSIX_SOURCE

void showInitialMessage();
int show_prompt();
void run_program (char **items, int num);
void myexit();
void mypwd();
void mydir(char *path);
void mycd(char *path);
int mycp(char *, char *);
void sighandler(int signum);


int main (){
  signal(SIGINT, sighandler);
  int option = 0;

  showInitialMessage();
  while(1) option = show_prompt();
}

int show_prompt(){
  char ** items;
  int num, background;
  char expresion[TAM];
  printf ("=> ");
  fgets (expresion, TAM, stdin);

  num = separaItems (expresion, &items, &background);

  if (num>0){
    run_program(items, num);
    liberaItems (items);
  }
  return 0;

}

void run_program (char **items, int num){
  if (strcmp(items[0], "myexit") == 0) myexit();
  if (strcmp(items[0], "mypwd") == 0) mypwd();
  if (strcmp(items[0], "mycd") == 0) mycd(items[1]);
  if (strcmp(items[0], "mycp") == 0) {
    if (num == 3) {
      mycp(items[1], items[2]);
    } else {
      printf("Número de argumentos invalidos\n");
    }
  }

  if (strcmp(items[0], "mydir") == 0) {
    if (num == 1) {
      mydir(".");
    } else if (num == 2){
      mydir(items[1]);
    } else {
      printf("Error\n\n");
    }
  }
}

void myexit(){
  printf("\nGracias por usar nuestro programa, Adios\n\n");
  exit(0);
}

void mypwd(){
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL)
  printf("%s\n", cwd);
  else
  perror("getcwd() error");
}

void mydir(char *path){
  DIR *d;
  struct dirent *dir;
  d = opendir(path);
  if (d){
    while ((dir = readdir(d)) != NULL){
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  printf("\n");
}


void mycd(char *path){
  chdir(path);
}

int mycp(char *fnSrc, char *fnDest){
  FILE *fpDest, *fpSrc;
  int c;

  if ((fpDest = fopen(fnDest, "w")) && (fpSrc = fopen(fnSrc, "r"))) {
    while ((c = getc(fpSrc)) != EOF) putc(c, fpDest);
    fclose(fpDest);
    fclose(fpSrc);
    return 0;
  }
  return -1;
}

void sighandler(int signum){
  printf("\nEjecuta el comando 'myexit'\n");
  printf("\n=> ");
  fflush(stdout);
}

void showInitialMessage(){
  printf("\n          MI COMMAND LINE \n");
  printf("Bienvenido a la linea de comandos :D \n");
  printf("...........................................\n\n");
}
