#include <stdio.h>

int main(void) {
  printf("Hello CMake! \n");
  int a = 1;
  int *b = &a;
  int c = 3;
  printf("a:%d \n", a);
  printf("*b:%d \n", *b);
  printf("c:%d \n", c);
  printf("++a: %d \n" ,++a);
  return 0;
}