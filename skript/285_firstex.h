#include <stdlib.h>

int fun(int x) {
  if (x <= 0) {
    return -1;
  }
  int *mem = new int[2 * x];
  for (int i = 0; i < 2 * x; ++i) {
    mem[i] = rand() % 1000;
  }
  if (x > 10) {
    x += 10;
    if (x < 100) {
      if (x % 42 == 0) {
        x *= 17;
      }
    }
  } else {
    x /= 2;
  }
  int val = mem[x];
  delete[] mem;
  return val;
}
