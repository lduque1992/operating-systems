
/**
* Realizar un programa que capture la edad de un usuario en años  y de acuerdo a la misma,
* indicar si es un bebé (0 a 2), un niño (3 a 12), un adolescente (13 a 17)
* o un adulto (18 en adelante) y mostrar su edad en meses.
*
* La  salida  debe  tener  la  siguiente  forma:
*
* | Clasificación por edad | Edad en meses        |
* -------------------------------------------------
* |      usted es un Adulto| Usted tiene 240 meses|
*
* By: James Garzón Otálvaro
*/

#include <stdio.h>

char *getUserCategoryString(int age);
int getMonthsFromAge(int age);

int main() {
    char titleClassification[] = "Clasificacion por edad";
    char titleAge[] = "Edad en meses";
    int age;

    printf("\n Ingrese su edad en años: ");
    scanf("%d", &age);

    int months = getMonthsFromAge(age);


    printf("\n|%-25s|%-25s|\n", titleClassification, titleAge);
    printf("--------------------------------------------------------\n");
    printf("|%25s|%25d|\n\n", getUserCategoryString(age), months);

    return 0;
}

/**
* Get the user category depending of the age
* @param {int} age
* @return {char}
*/
char *getUserCategoryString(int age){

    if (age <= 2) {
        return "Usted es un Bebe";
    }else if (age <= 12) {
        return "Usted es un Nino";
    }else if (age <= 17) {
        return "Usted es un Adolescente";
    }else if (age >= 18) {
        return "Usted es un Adulto";
    }
    return "";
}

/**
* Get month from age
* @param {int} age
* @return {char}
*/
int getMonthsFromAge(int age){
    return age * 12;
}
