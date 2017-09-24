#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int c;
    FILE *file;
    file = fopen("input.txt", "r+");
    if (file) {
        while ((c = getc(file)) != EOF){
            putchar(c);
        }

        fputc('x', file);
        fclose(file);
    }

    return 0;
}

// #include <stdio.h>
//
// int main ()
// {
//    FILE *fp;
//    int ch;
//
//    fp = fopen("input.txt", "w+");
//    for( ch = 0 ; ch <= 400; ch++ )
//    {
//       fputc('x', fp);
//    }
//    fclose(fp);
//
//    return(0);
// }
