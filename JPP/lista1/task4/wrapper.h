#ifndef WRAPPER_H
#define WRAPPER_H

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    long long int x;
    long long int y;
} Diophantine_Solution;

Diophantine_Solution my_library__solve_diophantine_loop(\
                            long long int a,\
                            long long int b, \
                            long long int c);
Diophantine_Solution my_library__solve_diophantine_recursive(\
                            long long int a, \
                            long long int b, \
                            long long int c);

long long int my_library__factorial_loop(long long int n);
long long int my_library__factorial_recursive(long long int n);

long long int my_library__gcd_loop(long long int a, long long int b);
long long int my_library__gcd_recursive(long long int a, long long int b);

#endif /* C_WRAPPER_H */