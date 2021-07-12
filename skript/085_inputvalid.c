#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char buf[20];
  if (argc < 2) {
    return -1;
  }
  if (strlen(argv[1]) >= sizeof(buf)) {
    printf("argument too long\n");
    return 1;
  }
  strcpy(buf, argv[1]);
  for (size_t i = 0; i < strlen(buf); ++i) {
    buf[i] = tolower(buf[i]);
  }
  printf("%s\n", buf);
}
