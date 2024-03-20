#include "library_whole.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <a> <b> <c>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    unsigned long long fact_recursive = factorial_recursive(a);
    unsigned long long fact_loop = factorial_loop(a);
    printf("Factorial_recursive of %d is %llu\n", a, fact_recursive);
    printf("Factorial_loop of %d is %llu\n", a, fact_loop);

    int gcd_result_recursive = gcd_recursive(a, b);
    int gcd_result_loop = gcd_loop(a, b);
    printf("GCD_recursive of %d and %d is %d\n", a, b, gcd_result_recursive);
    printf("GCD_loop of %d and %d is %d\n", a, b, gcd_result_loop);

    DiophantineSolution diophantine_solution_recursive = solve_diophantine_recursive(a, b, c);
    DiophantineSolution diophantine_solution_loop = solve_diophantine_loop(a, b, c);
    printf("Solution for Diophantine equation_recursive %dx + %dy = %d is x = %d, y = %d\n", a, b, c, diophantine_solution_recursive.x, diophantine_solution_recursive.y);
    printf("Solution for Diophantine equation_loop %dx + %dy = %d is x = %d, y = %d\n", a, b, c, diophantine_solution_loop.x, diophantine_solution_loop.y);

    return 0;
}