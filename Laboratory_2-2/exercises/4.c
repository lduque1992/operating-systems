#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME[] = "input.txt";
const char FILE_NAME_OUTPUT[] = "copy.txt";

int main(int argc, char const *argv[]) {
  int count = 0; // chars readed
  FILE *in_file;
  FILE *out_file;
  int ch;

  // Open file
  in_file = fopen(FILE_NAME, "r"); //Open file
  out_file = fopen(FILE_NAME_OUTPUT, "ab+"); //Open file

  // Allways make this verefication
  if (in_file == NULL) { // File doesn't exist
    printf("No se puede abrir el archivo %s\n", FILE_NAME);
    exit(8);
  }
  // Read file
  while(1){
    ch = fgetc(in_file);
    printf("%c", ch);
    fputc(ch, out_file);
    if (ch == EOF) { // Read until the end of the file
      break;
    }
    count++;
  }

  printf("Número de caracteres del archivo %s: %d\n", FILE_NAME, count);

  // Close file
  fclose(in_file);
  return 0;
}
