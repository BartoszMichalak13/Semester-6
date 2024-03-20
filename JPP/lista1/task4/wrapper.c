/* my_ada_wrapper.c */
#include "wrapper.h"

extern long long int my_library__factorial_loop(long long int n);
extern long long int my_library__factorial_recursive(long long int n);

extern long long int my_library__gcd_loop(long long int a, long long int b);
extern long long int my_library__gcd_recursive(long long int a, long long int b);

extern Diophantine_Solution my_library__solve_diophantine_loop(long long int a, long long int b, long long int c);
extern Diophantine_Solution my_library__solve_diophantine_recursive(long long int a, long long int b, long long int c);

long long int c_factorial_loop(long long int n) {
  return my_library__factorial_loop(n);
}
long long int c_factorial_recursive(long long int n) {
  return my_library__factorial_recursive(n);
}

long long int c_gcd_loop(long long int a, long long int b) {
  return my_library__gcd_loop(a,b);
}
long long int c_gcd_recursive(long long int a, long long int b) {
  return my_library__gcd_recursive(a,b);
}

Diophantine_Solution c_solve_diophantine_loop(long long int a, long long int b, long long int c) {
  return my_library__solve_diophantine_loop(a,b,c);
}
Diophantine_Solution c_solve_diophantine_recursive(long long int a, long long int b, long long int c) {   my_library__solve_diophantine_recursive(a,b,c);
  return my_library__solve_diophantine_recursive(a,b,c);
}

