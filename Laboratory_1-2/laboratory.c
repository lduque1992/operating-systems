/**
*
*
*/

#include <stdio.h>

int compareInts(int a, int b);
void printAnswer(int answer, int a, int b);

int main() {
  int firstNumber;
  int secondNumber;
  int answer;

  printf("\nIngrese el primer número: ");
  scanf("%d", &firstNumber);

  printf("Ingrese el segundo número: ");
  scanf("%d", &secondNumber);

  answer = compareInts(firstNumber, secondNumber);
  printAnswer(answer, firstNumber, secondNumber);
  return 0;
}

int compareInts(int a, int b){
  if (a > b) {
    return 1;
  }else if (a == b) {
    return 0;
  }else{
    return -1;
  }
}

void printAnswer(int answer, int a, int b){
  switch (answer) {
    case 0:
    printf("Los numeros son iguales\n\n");
    break;
    case 1:
    printf("El número mayor es %d\n\n", a);
    break;
    case -1:
    printf("El número mayor es %d\n\n", b);
    break;
  }
}
