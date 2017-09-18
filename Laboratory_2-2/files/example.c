#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME[] = "input.txt";

int main() {
  int count = 0; // chars readed
  FILE *in_file;
  int ch;

  // Open file
  in_file = fopen(FILE_NAME, "r"); //Open file

  // Allways make this verefication
  if (in_file == NULL) { // File doesn't exist
    printf("No se puede abrir el archivo %s\n", FILE_NAME);
    exit(8);
  }
  // Read file
  while(1){
    ch = fgetc(in_file);
    printf("%c", ch);
    if (ch == EOF) { // Read until the end of the file
      break;
    }
    count++;
  }

  fputc('x', in_file);
  printf("Número de caracteres del archivo %s: %d\n", FILE_NAME, count);

  // Close file
  fclose(in_file);
  return 0;
}
