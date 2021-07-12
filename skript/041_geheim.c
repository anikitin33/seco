#include <stdio.h>
#include <string.h>

const char *secret = "swordfish";
const char *flag = "GOLD";
const char *niete = "****";

int main(int argc, const char *argv[]) {
  if (argc > 1 && strcmp(argv[1], secret) == 0) {
    printf("%s\n", flag);
  } else {
    printf("%s\n", niete);
  }
}
