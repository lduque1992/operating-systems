#include <stdio.h>
#include <stdlib.h>

int main() {
  // Malloc return a pointer, so we need one
  int *age;

  // Malloc return a generic pointer
  // We need to cast it
  age = (int *)malloc(sizeof(int));
  printf("Edad en años: ");
  setbuf(stdin, NULL);
  scanf("%d", age);

  printf("Usted tiene %d meses de vida\n", (*age) * 12);

  // Free memory
  free(age);
  return 0;
}
