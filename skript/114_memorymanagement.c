#include <stdlib.h>
int main() {
  char *pm = (char *)malloc(8);
  char *pc = (char *)calloc(8, 1);

  // printf("%s\n %s\n", pm, pc);

  free(pm);
  free(pc);

  return 1;
}
