#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int checksub(int val, unsigned int diff) {
  if (val < 0) {
    if (val < INT_MIN + diff) {
      printf("-/+ WARP\n");
      return val;
    }
  } else {
    if (diff > val) {
      printf("+/- WARP\n");
      return val;
    }
  }

  return val - diff;
}

int main() {
  printf("-- checksub --\n");

  int val = INT_MAX;
  unsigned int diff = -1;
  int res = 0;
  res = checksub(val, diff);

  if (res == val && diff == 0) {
    printf("secure new val = %d\n\n", val);
  } else if (res == val && diff != 0) {
    printf("old val = %d\n\n", val);
  } else {
    printf("secure new val = %d\n\n", val);
  }

  return 1;
}
