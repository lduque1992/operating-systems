#include <stdio.h>
#include <string.h>

// struct point {
//   int x;
//   int y;
// };

struct student {
  char name[40];
  int numStudent;
  float grade;
};


int main(int argc, char const *argv[]) {
  // struct point p;
  // struct point *p_ptr;
  // p_ptr = &p;
  // (*p_ptr).x = 9;
  // p_ptr -> y = 8;
  // printf("%d\n", p_ptr->x);
  // printf("%d\n", p.y);

  struct student student;
  struct student *ptr_student = &student;
  strcpy(ptr_student -> name, "James");
  (*ptr_student).numStudent = 6;
  ptr_student -> grade = 4.9;

  printf("%s\n", ptr_student->name);
  printf("%d\n", (*ptr_student).numStudent);
  printf("%f\n", ptr_student->grade);
  return 0;
}
