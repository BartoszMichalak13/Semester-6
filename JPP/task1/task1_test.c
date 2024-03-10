#include "task1.h"

int main() {
    int n = 5;
    printf("Factorial of %d is %llu\n", n, factorial(n));

    int a = 30, b = 12;
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));

    int c = 42;
    DiophantineSolution solution = solve_diophantine(a, b, c);
    printf("Solution to %dx + %dy = %d is x = %d, y = %d\n", a, b, c, solution.x, solution.y);

    // Test recursive versions
    printf("Recursive factorial of %d is %llu\n", n, factorial_recursive(n));
    printf("Recursive GCD of %d and %d is %d\n", a, b, gcd_recursive(a, b));
    DiophantineSolution recursive_solution = solve_diophantine_recursive(a, b, c, 0, 1);
    printf("Recursive solution to %dx + %dy = %d is x = %d, y = %d\n", a, b, c, recursive_solution.x, recursive_solution.y);

    return 0;
}
