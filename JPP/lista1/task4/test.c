// test_wrapper.c
#include "wrapper.h"
#include <stdio.h>

long long int c_factorial_loop(long long int n);
long long int c_factorial_recursive(long long int n);

long long int c_gcd_loop(long long int a, long long int b);
long long int c_gcd_recursive(long long int a, long long int b);

Diophantine_Solution c_solve_diophantine_loop(long long int a, long long int b, long long int c);
Diophantine_Solution c_solve_diophantine_recursive(long long int a, long long int b, long long int c);

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <a> <b> <c>\n", argv[0]);
    return 1;
  }
  long long int a = atoi(argv[1]);
  long long int b = atoi(argv[2]);
  long long int c = atoi(argv[3]);

  long long int result = c_factorial_loop(a);
  if (result == -1) {
    printf("Error: Factorial_loop of %lld overflows.\n", a);
  } else {
    printf("Factorial_loop of %lld is %lld\n", a, result);
  }

  result = c_factorial_recursive(a);
  if (result == 0) {
    printf("Error: Factorial_recursive of %lld overflows.\n", a);
  } else {
    printf("Factorial_recursive of %lld is %lld\n", a, result);
  }

  result = c_gcd_loop(a,b);
  printf("gcd_loop(%lld,%lld) = %lld\n", a, b, result);  
  result = c_gcd_recursive(a,b);
  printf("gcd_recursive(%lld,%lld) = %lld\n", a, b, result);

  Diophantine_Solution res = c_solve_diophantine_loop(a,b,c);
  printf("solve_diophantine_loop: x * %lld + y * %lld = %lld; x = %lld, y = %lld\n", a, b, c, res.x, res.y);  
  res = c_solve_diophantine_recursive(a,b,c);
  printf("solve_diophantine_loop: x * %lld + y * %lld = %lld; x = %lld, y = %lld\n", a, b, c, res.x, res.y);
  return 0;
}
