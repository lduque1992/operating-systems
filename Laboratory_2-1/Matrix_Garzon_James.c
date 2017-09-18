#include<stdio.h>
#include<stdlib.h>


/* Functions to provide */
int** create_matrix(int order);
void print_matrix(int** matrix, int order);
void free_matrix(int**, int order);
int** mult_matrix(int** m_A, int** m_B, int order);
void fillMatrix(int** matrix, int order);

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

  printf("\nCreating Matrix A:\n");
  matrix_A = create_matrix(order);
  fillMatrix(matrix_A, order);
  print_matrix(matrix_A, order);

  printf("\nCreating Matrix B:\n");
  matrix_B = create_matrix(order);
  fillMatrix(matrix_B, order);
  print_matrix(matrix_B, order);

  printf("\nMultiplying Matrices A * B:\n");
  matrix_R = mult_matrix(matrix_A, matrix_B, order);
  print_matrix(matrix_R, order);

  printf("\nfreeing memory...\n");
  free_matrix(matrix_A, order);
  free_matrix(matrix_B, order);
  free_matrix(matrix_R, order);
  return 0;
}

void fillMatrix(int** matrix, int order){
  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      printf("Enter value of matrix[%d][%d]: ",i,j );
      scanf("%d", &matrix[i][j]);
    }
  }
}

int** create_matrix(int order){
  int** matrix = malloc(sizeof(int*)*order);
  for (int i = 0; i < order; i++) {
    matrix[i] = (int*) malloc(sizeof(int)*order);
  }

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      matrix[i][j] = 0;
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
  free (matrix);
}

int** mult_matrix(int** m_A, int** m_B, int order){
  int** m_R = malloc(sizeof(int*)*order);
  int value = 0;
  m_R = create_matrix(order);
  printf("In mult_matrix\n");

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      value = 0;
      for (int k = 0; k < order; k++) {
        value = value + m_A[i][k] * m_B[k][j];
      }
      m_R[i][j] = value;
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
