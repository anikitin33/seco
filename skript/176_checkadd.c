#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int checkadd1(unsigned int val, int diff) {
  if (val + diff > UINT_MAX) {
    printf("ERROR +wrap, no change\n");
    return val;
  }
  return val + diff;
}

unsigned int checkadd2(unsigned int val, int diff) {
  if (val > UINT_MAX - diff) {
    printf("ERROR +wrap, no change\n");
    return val;
  }
  return val + diff;
}

unsigned int checkadd3(unsigned int val, int diff) {
  if (val > UINT_MAX - diff) {
    printf("ERROR +warp, no change\n");
    return val;
    // } else if (val + diff < 0) // NEIN!
  } else if (val < -diff) {  // fast
    printf("ERROR -wrap, no change\n");
    return val;
  }
  return val + diff;
}

/*unsigned int checkadd3(unsigned int val, int diff) {
  if (val > UINT_MAX - diff) {
    printf("ERROR +warp, no change\n");
    return val;
  } else if (val < -diff) {  // fast
    printf("ERROR -wrap, no change\n");
    return val;
  }
  return val + diff;
}*/

unsigned int checkadd4(unsigned int val, int diff) {
  if (diff < 0) {
    if (val < -diff) {
      printf("ERROR -wrap, no change\n");
      return val;
    }
  } else {  // diff >= 0
    if (val > UINT_MAX - diff) {
      printf("ERROR +warp, no change\n");
      return val;
    }
  }
  return val + diff;
}

int main() {
  printf("-- checkadd1 --\n");

  unsigned int val = UINT_MAX - 2;
  val = checkadd1(val, 4);
  printf("val = %u\n\n", val);

  printf("-- checkadd2 --\n");

  val = UINT_MAX - 2;
  val = checkadd2(val, 4);
  printf("val = %u\n", val);

  val = 2;
  val = checkadd2(val, -4);
  printf("val = %u\n\n", val);

  printf("-- checkadd3 --\n");

  val = 2;
  val = checkadd3(val, -4);
  printf("val = %u\n", val);

  val = INT_MAX;
  val += 41;
  int diff = INT_MIN + 2;
  printf("val = %u\n\n", val);
  val = checkadd3(val, diff);
  printf("val = %u\n\n", val);

  printf("-- checkadd4 --\n");

  val = checkadd4(val, diff);
  printf("val = %u\n", val);

  val = INT_MAX;
  val += 43;
  diff = INT_MIN;
  val = checkadd4(val, diff);
  printf("val = %u\n", val);

  val = INT_MAX;
  val -= 17;
  val = checkadd4(val, diff);
  printf("val = %u\n", val);

  return 1;
}
