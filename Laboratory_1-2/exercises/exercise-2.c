
/**
* Diseñar un programa que calcule el área y el perímetro de un triángulo rectángulo
* dada la  base  y  la  altura  (sus  dos  catetos).
*
* La  salida  debe  tener  la  siguiente  forma:
* El área del triángulo de base [...] cm y altura [...] cm es [...] cm2.
* El perímetro del triángulo de base [...] cm y altura [...] cm es [...] cm.
*
* By: James Garzón Otálvaro
*/

#include <stdio.h>
#include <math.h>

float getArea(float base, float height);
float getPerimeter(float base, float height);

int main() {
    float base;
    float height;

    //Get the base and height from console
    printf("\nIngrese la base del triángulo rectángulo: ");
    scanf("%f", &base);
    printf("Ingrese la altura del triángulo rectángulo: ");
    scanf("%f", &height);

    const float area = getArea(base, height);
    const float perimeter = getPerimeter(base, height);

    printf("\nEl área del triángulo de base %.2f cm y altura %.2f cm es %.2f cm2.\n", base, height, area);
    printf("El perímetro del triángulo de base %.2f cm y altura %.2f cm es %.2f cm.\n\n", base, height, perimeter);
    return 0;
}

/**
* Calculate and return the area of a rectangle triangle
* @param {int} base
* @param {int} height
* @return {int}
*/
float getArea(float base, float height){
    float area = (base * height)/2;
    return area;
}

/**
* Calculate and return the perimeter of a rectangle triangle
* @param {int} base
* @param {int} height
* @return {int}
*/
float getPerimeter(float base, float height){
    float h = powf(base, 2) + powf(height, 2);
    h = sqrtf(h);
    return h + base + height;
}
