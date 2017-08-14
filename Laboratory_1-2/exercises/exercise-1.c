
/*
* Diseñe un programa que lea un entero y determine si es par o impar.
*
* La salida debe tener la siguiente forma:
* El número [...] es [par/impar].
*
* By: James Garzón Otálvaro
*/

#include <stdio.h>

char *isEvenOrOdd(int number);

int main() {
    int number;
    printf("\nPor favor ingrese un número entero: ");
    scanf("%d", &number);
    printf("El número %d es %s\n\n", number, isEvenOrOdd(number));
    return 0;
}

/**
* Return "Par" if the number is Even or "Impar" if is Odd
* @param {int} number
* @return {char}
*/
char *isEvenOrOdd(int number){
    const int numberModuleTwo = number%2;

    switch (numberModuleTwo) {
        case 0:
        return "par";
        default :
        return "impar";
    }

}
