#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = -9;
  unsigned int b = 8;
  char *p = (char *)malloc(1);
  printf("%u\n", b + a);

  return 1;
}
