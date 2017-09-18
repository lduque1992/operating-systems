#include<stdio.h>
#include<stdlib.h>

/* This program can create, multiply and print 2D-matrices*/

/* Functions to provide */
int** create_matrix(int order);
void print_matrix(int** matrix, int order);
void free_matrix(int**, int order);
int** mult_matrix(int** m_A, int** m_B, int order);

int main(int argc, char *argv[]){

  int** matrix_A;
  int** matrix_B;
  int** matrix_R;
  int order;

  if( argc != 2 ){
    printf("ERROR: you need to provide the square matrices order\n");
    return -1;
  }
  else{
    printf("The matrices order is %s x %s\n",argv[1],argv[1]);
  }

  order = atoi(argv[1]);

  printf("Creating Matrix A:\n");
  matrix_A = create_matrix(order);
  print_matrix(matrix_A, order);
  // TODO: call function to create matrix_A
  // TODO: call function to print matrix_A

  printf("Creating Matrix B:\n");
  matrix_B = create_matrix(order);
  print_matrix(matrix_B, order);
  // TODO: call function to create matrix_B
  // TODO: call function to print matrix_B

  printf("Multiplying Matrices A * B:\n");
  matrix_R = mult_matrix(matrix_A, matrix_B, order);
  print_matrix(matrix_B, order);
  // TODO: call function to multiply A * B
  // TODO: call function to print result R

  printf("freeing memory...\n");
  // TODO: call function to free matrices memory
  return 0;
}

int** create_matrix(int order){
  int** matrix = malloc(sizeof(int*)*order);

  for (int i = 0; i < order; i++) {
    matrix[i] = (int*) malloc(sizeof(int)*order);
  }

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      matrix[i][j] = 2;
    }
  }
  return matrix;
}

void print_matrix(int** matrix, int order){
  // TODO: print matrix
  printf("In print_matrix\n");
  for (int i = 0; i < (order); i++) {
    printf("[ ");
    for (int j = 0; j < order; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("]\n");
  }
}

void free_matrix(int** matrix, int order){
  // TODO: use free() to free matrix's memory
  printf("In free_matrix\n");
}

int** mult_matrix(int** m_A, int** m_B, int order){
  // TODO: create memory to result matrix
  // TODO: Multiply matrices
  int** m_R;
  int value = 0;
  m_R = create_matrix(order);
  printf("In mult_matrix\n");

  for (int i = 0; i < order; i++) {
    value = 0;
    for (int j = 0; j < order; j++) {
      value = value + (m_A[i][j] * m_B[j][i]);
      for (int k = 0; k < order; k++) {

      }
    }
  }

  return m_R;
}


// 1) (int **) malloc(sizeof(int)*order*order)
// 2)  matriz = (int **) malloc(sizeof(int*)*order);
//     matriz[0] = (int*) malloc(sizeof(int)*order);
//
// char (* b)[10] => apuntador a un arreglo de caracteres (size = 3)
// char *b[10] => arreglo de apuntadores (size = 10)
