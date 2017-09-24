#include <stdio.h>
int main() {
  char nombres[3][10] = {"Maria", "Daniela", "Carla"};
  int i;
  char *a;
  char(*b)[10];

  a = (char *) nombres;
  printf("El nombre es %s \n",a);
  for (i = 0; i < 10; i++){
    if(*a != '\0'){
      printf("El nombre[0][%d] es %c \n", i, *a);
      a++;
    }
  }

  b = (char(*) [10])nombres;
  for (i = 0; i < 3; i++){
    printf("El nombre[%d] es %s \n", i, (char*)(b));
    b++;
  }
  return 0;
}
