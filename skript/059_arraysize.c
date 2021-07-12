#include <stdio.h>
#include <string.h>

void fun(const char s[]) {
  // void fun(const char *s) { // Problem sichtbar
  printf("size=%zd\n", sizeof(s));
}

int main(void) {
  int a = 1;
  printf("&a = %#010x\n", &a);
  volatile char s[10] = "hallo";
  volatile char *s_ptr = "hallo00";

  printf("s_ptr p = %p\n", s_ptr);
  printf("s_ptr &s = %#010x\n\n", &s_ptr);

  printf("s p = %p\n", s);
  printf("s &s = %#010x\n\n", &s);

  printf("s = %s\n", s);
  printf("s_ptr = %s\n\n", s_ptr);

  printf("sizeof(char)=%zd\n\n", sizeof(char));

  printf("char s[]: sizeof(s)=%zd\n", sizeof(s));
  printf("char s[]: strlen=%zd\n", strlen(s));
  printf("char s[]: sizeof(s)/sizeof(char)=%zd\n\n", sizeof(s) / sizeof(char));

  printf("char * s: sizeof(s)=%zd\n", sizeof(s_ptr));
  printf("char * s: strlen=%zd\n", strlen(s_ptr));
  printf("char * s: sizeof(s)/sizeof(char)=%zd\n",
         sizeof(s_ptr) / sizeof(char));

  fun(s);
}
