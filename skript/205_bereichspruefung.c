#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
bool check_add(int op1, int op2) {
  unsigned int usum = (unsigned int)op1 + op2;
  bool err = (usum ^ op1) & (usum ^ op2) & INT_MIN;
  return !err;
}

bool check_unsigned_add(unsigned op1, unsigned op2) {
  bool err = UINT_MAX - op1 < op2;
  return err;
}

bool check_signed_sub(int op1, int op2) {
  bool err = (op1 ^ op2) & (((unsigned int)op1 - op2) ^ op1) & INT_MIN;
  return !err;
}

bool check_signed_mul(int op1, int op2) {
  if ((op2 == 0) || ((op1 == INT_MIN) && (op2 == -1))) return 0;
  if (op1 > UINT_MAX / op2) return 0;
  if (op2 > UINT_MAX / op1) return 0;

  return 1;
}

int main() {
  int checks[] = {1, 2,       -1, 1,           -3, -4,      INT_MIN,
                  3, INT_MAX, -2, INT_MAX - 2, 4,  INT_MIN, -2};

  size_t len = sizeof(checks) / sizeof(int);

  for (size_t idx = 0; idx < len; idx += 2) {
    int op1 = checks[idx], op2 = checks[idx + 1];
    printf("%12d + %12d ist %s\n", op1, op2,
           check_add(op1, op2) ? "okay" : "aua!");
  }

  int op1, op2;

  op1 = INT_MIN;
  op2 = 2;

  printf("%12d - %12d ist %s\n", op1, op2,
         check_signed_sub(op1, op2) ? "okay" : "aua!");

  op1 = (INT_MAX / 2) - 1;
  op2 = 3;

  printf("%12d * %12d ist %s\n", op1, op2,
         check_signed_mul(op1, op2) ? "okay" : "aua!");
}
