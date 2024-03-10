#include "task1.h"
#include <limits.h>

unsigned long long factorial(int n) {
  // error
  if (n < 0){
    printf("Error: factorial of negative number is undefined\n");
    return 0;
  }
  
  unsigned long long result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}

int gcd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// DiophantineSolution solve_diophantine(int a, int b, int c) {
//     DiophantineSolution solution;
//     for (solution.x = INT_MIN; solution.x <= INT_MAX; ++solution.x) {
//         if ((c - a * solution.x) % b == 0) {
//             solution.y = (c - a * solution.x) / b;
//             return solution;
//         }
//     }
//     solution.x = 0; // If no solution found, return default values
//     solution.y = 0;
//     return solution;
// }
DiophantineSolution solve_diophantine(int a, int b, int c) {
  if (gcd(a,b) != c) {
    printf("Solution doesn't exists as gcd(%d,%d) != %d\n", a, b, c);
    return (DiophantineSolution){ .x = INT_MIN, .y = INT_MIN };
  }


  // function extended_gcd(a, b)
    int s = 0;    
    int old_s = 1;
    int r = b;    
    int old_r = a;
         
    while (r != 0) {
      int quotient = old_r / r;
      old_r =  r;
      r =  old_r - (quotient * r);
      old_s = s;
      s =  old_s - (quotient * s);
    }
    int bezout_t;
    if (b != 0) {
      bezout_t = (old_r - (old_s * a)) / b;
    } else {
      bezout_t = 0;
    }
    
    printf("Bézout coefficients: %d, %d\n", old_s, bezout_t);
    printf("Greatest common divisor: %d\n", old_r);
    // DiophantineSolution solution;
    // solution.x = old_s; // If no solution found, return default values
    // solution.y = bezout_t;
    return (DiophantineSolution){ .x = old_s, .y = bezout_t };
}
