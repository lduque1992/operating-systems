#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int show_prompt(char *text);
void showInitialMessage();
void sighandler(int signum);
void catch_command();
void mypwd();

int main(int argc, char const *argv[]) {
  signal(SIGINT, sighandler);
  catch_command();

  return 0;
}

void catch_command(){
  char text[100];
  while (show_prompt(text) != 0){
    if (strcmp(text, "mypwd") == 0) {
      mypwd();
      // printf("/Users/james/Courses/C-programming/operating-systems/Laboratory_3/Command\n");
    }
  }
}

int show_prompt(char *text){
  int result = -1;
  printf("=> ");
  scanf("%s", text);
  result = strcmp(text, "myexit");
  return result;
}

void showInitialMessage(){
  printf("\n          MY COMMAND LINE \n");
  printf("Wellcome to the custom command line :D \n");
  printf("...........................................\n\n");
}

void sighandler(int signum){
  // printf("Caught signal %d, coming out...\n", signum);
  printf("Para salir ingrese el comando 'myexit'\n");
}

void mypwd(){
  // system("dirs +0");
  char cwd[1024];
   if (getcwd(cwd, sizeof(cwd)) != NULL){
       fprintf(stdout, "Current working dir: %s\n", cwd);
   } else{
       perror("getcwd() error");
     }
}
