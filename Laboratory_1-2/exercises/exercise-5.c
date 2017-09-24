
/**
* Realice un programa que solicite una palabra e indique si esta inicia o no con una vocal.
*
* La  salida  debe  tener  la  siguiente  forma:
* La palabra [...] comienza con la vocal [...].
*
* By: James Garzón Otálvaro
*/

#include <stdio.h>
#include <string.h>
int checkFirstLetterVowel(char *text);

int main() {
    char word[50];
    int isVowel;
    printf("Ingrese una palabra: ");
    scanf("%s", word);

    isVowel = checkFirstLetterVowel(word);

    if (isVowel == 1) {
        printf("La palabra '%s' comienza con la vocal %c.\n", word, word[0]);
    }else{
        printf("La palabra '%s' no comienza con una vocal. \n", word);
    }
    return 0;
}


int checkFirstLetterVowel(char *text){
    if (text[0] == 'a'
    || text[0] == 'e'
    || text[0] == 'i'
    || text[0] == 'o'
    || text[0] == 'u'
    || text[0] == 'A'
    || text[0] == 'E'
    || text[0] == 'I'
    || text[0] == 'O'
    || text[0] == 'U' ) {
        return 1;
    }else {
        return 0;
    }
}
