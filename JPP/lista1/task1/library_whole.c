#include "library_whole.h"
#include <limits.h>
#include <math.h>

unsigned long long factorial_recursive(unsigned long long n) {
  if (n < 0) { // error
    return 0;
  }
  if (n == 0)
    return 1;
  else
    return n * factorial_recursive(n - 1);
}

int gcd_recursive(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd_recursive(b, a % b);
}

DiophantineSolution solve_diophantine_recursive(int a, int b, int c) {
  DiophantineSolution solution;
  int gcd_res = gcd_recursive(a,b);
  int rem = c % gcd_res;
  if (rem != 0) {
    printf("Solution doesn't exist as %d is not multplie of gcd(%d,%d) \n", c, a, b);
    return (DiophantineSolution){ .x = INT_MIN, .y = INT_MIN };
  }
  if (b == 0) {
    solution.x = floor(c / a);
    solution.y = 0;
    return solution;
  } else {
    DiophantineSolution d = solve_diophantine_recursive(b, a % b, c);
    solution.x = d.y;
    solution.y = floor(d.x - (a / b) * d.y);
    return solution;
  }
}

unsigned long long factorial_loop(unsigned long long n) {
  // error
  if (n < 0) {
    return 0;
  }
  
  unsigned long long result = 1;
  for (unsigned long long i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

/*
  Swaps 2 ints if b > a
  Usage: swap(&a,&b);
*/
void swap(int *a, int *b) {
  if (*(b) > *(a)) {
    int tmp = *(a);
    *(a) = *(b);
    *(b) = tmp;
  }
}

int gcd_loop(int a, int b) {
  swap(&a,&b);
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

DiophantineSolution solve_diophantine_loop(int a, int b, int c) {
  int gcd_res = gcd_loop(a,b);
  int rem = c % gcd_res;
  if (rem != 0) {
    printf("Solution doesn't exist as %d is not multplie of gcd(%d,%d) \n", c, a, b);
    return (DiophantineSolution){ .x = INT_MIN, .y = INT_MIN };
  }
  // function extended_gcd(a, b)
  int s = 0;    
  int old_s = 1;
  int r = b;    
  int old_r = a;

  while (r != 0) {
    int quotient = floor(old_r / r);
    int tmp = old_r;
    old_r = r;
    r = tmp - (quotient * r);
    tmp = old_s;
    old_s = s;
    s = tmp - (quotient * s);
  }

  int bezout_t;
  if (b != 0) {
    bezout_t = (old_r - (old_s * a)) / b;
  } else {
    bezout_t = 0;
  }
  return (DiophantineSolution){ .x = old_s*(c / gcd_res), .y = bezout_t*(c / gcd_res) };
}
