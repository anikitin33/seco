
#include <stdio.h>

int main(const int argc, const char* argv[]) {
  const char* what = "C";
  printf("Hello %s World\n", what);

  for (int idx = 0; idx < argc; idx++) {
    printf(" %2d: %s\n", idx, argv[idx]);
  }
}
