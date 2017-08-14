
/**
* Diseñe un programa que reciba 5 nombres de pacientes junto con su estatura en metros.
*
* La  salida  debe  tener  la  siguiente  forma:
*
* El paciente #1 mide [...] metros.
* El paciente #2 mide [...] metros.
* El paciente #3 mide [...] metros.
* El paciente #4 mide [...] metros.
* El paciente #5 mide [...] metros.
*
* By: James Garzón Otálvaro
*/

#include <stdio.h>
#include <math.h>

int main() {
    float pacient1;
    float pacient2;
    float pacient3;
    float pacient4;
    float pacient5;

    //Get pacients data
    printf("\nIngrese la estatura del paciente #1: ");
    scanf("%f", &pacient1);
    printf("Ingrese la estatura del paciente #2: ");
    scanf("%f", &pacient2);
    printf("Ingrese la estatura del paciente #3: ");
    scanf("%f", &pacient3);
    printf("Ingrese la estatura del paciente #4: ");
    scanf("%f", &pacient4);
    printf("Ingrese la estatura del paciente #5: ");
    scanf("%f", &pacient5);

    printf("\nEl paciente #1 mide %.2f metros. \n", pacient1);
    printf("El paciente #2 mide %.2f metros. \n", pacient2);
    printf("El paciente #3 mide %.2f metros. \n", pacient3);
    printf("El paciente #4 mide %.2f metros. \n", pacient4);
    printf("El paciente #5 mide %.2f metros. \n\n", pacient5);
    return 0;
}
