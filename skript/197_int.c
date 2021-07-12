#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const unsigned int HIGH = INT_MAX - 42;
  const unsigned int LOW = 42;
  volatile unsigned int s1 = 0;
  volatile int s2;
  bool up = true;
  long cnt = 0;
  while (true) {
    ++cnt;
    if (cnt % 17171717 == 0) {
      printf("cnt=%12ld, s1=%12d\n", cnt, s1);
    }
    s1 = s1 + (up ? 10 : -10);
    volatile unsigned int s1b = s1;
    if (s1 % 2 == 0) {
      s2 = s1 / 2 + 1000;
      s1 = s2 * 2 - 2000;
      if (s1b != s1) {
        printf("s1b=%d, s2=%d, s1=%d\n", s1b, s2, s1);
        abort();
      }
    }
    if (s1 > HIGH) {
      up = false;
      s1 = HIGH;
    }
    if (s1 < LOW) {
      up = true;
      s2 = LOW;
    }
  }
}
