#include "task1.h"

unsigned long long factorial_recursive(int n) {
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

DiophantineSolution solve_diophantine_recursive(int a, int b, int c, int x, int y) {
    DiophantineSolution solution;
    if (b == 0) {
        solution.x = c / a;
        solution.y = 0;
        return solution;
    } else {
        int d = solve_diophantine_recursive(b, a % b, c, x, y);
        solution.x = y;
        solution.y = x - (a / b) * y;
        return solution;
    }
}
