#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int a[3];
  int i = 0;
  printf("Ingrese el primer numero entero: ");
  scanf("%d", &a[0]);
  printf("Ingrese el segundo numero entero: ");
  scanf("%d", &a[1]);
  printf("Ingrese el tercer numero entero: ");
  scanf("%d", &a[2]);

  printf("Numéros ingresados: \n");
  while (i<3) {
    printf("%d\n", a[i]);
    i++;
  }
  return 0;
}
