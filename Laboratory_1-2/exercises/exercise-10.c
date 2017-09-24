/**
* a) El programa debe solicitar números hasta que el usuario ingrese el carácter “x” o
* ingrese un máximo 10 números.
* b) El programa debe determinar el promedio de los números ingresados.
* c) El programa debe determinar cuál es el número ingresado más grande y el más pequeño.
*
* Al finalizar, el programa debe imprimir cuántos números se ingresaron,
* el promedio y los dos números limite.
*
* El texto de salida debe tener un formato de tabla como se muestra a continuación:
*
* |     Números ingresados|8      |
* |     Número más pequeño|2      |
* |      Numero más grande|31     |
* |               Promedio|25     |
*
* By: James Garzón Otálvaro
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNumbers(float *values);
// void printNumbers(int *values);
float getMean(int *values, int size);

int main() {
  float a[10];
  int numbersSize = 0;
  float mean = 0;
  // int max = 0;
  // int min = 0;

  numbersSize = getNumbers(a);
  mean = getMean(a, numbersSize);
  // printNumbers(a);

  printf("\nLa media es: %f \n", mean);
  return 0;
}

int getNumbers(float *values) {
  char input[50];
  int i = 0;
  int flag = 0;
  while (i<10 && flag==0) {
    printf("Ingrese un número: ");
    scanf("%s", input);
    if (strcmp("x",input) == 0){
      flag = 1;
    }else {
      values[i] = atof(input);
    }
    i++;
  }
  if (flag == 1) {
    return i - 1;
  }else {
    return i;
  }
}

// void printNumbers(int *values){
//   int i = 0;
//   printf("\nArray values:\n");
//   do {
//     printf("%d\n", values[i]);
//     i++;
//   } while(i<10);
// }

float getMean(int *values, int size){
  int i = 0;
  int sum = 0;
  int mean = 0;
  for (i = 0; i < size; i++) {
    sum = sum + values[i];
  }
  mean = sum/size;
  return mean;
}
