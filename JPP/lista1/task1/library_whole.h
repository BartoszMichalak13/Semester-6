#include <stdio.h>

/*
  Funkcja obliczająca silnię n!
  returns 0 if n < 0
*/
unsigned long long factorial_recursive(unsigned long long n);
unsigned long long factorial_loop(unsigned long long n);

// Funkcja obliczająca największy wspólny dzielnik dwóch liczb naturalnych
int gcd_recursive(int a, int b);
int gcd_loop(int a, int b);

// Struktura przechowująca rozwiązanie równania diofantycznego ax + by = c
typedef struct {
    int x;
    int y;
} DiophantineSolution;

// Funkcja rozwiązująca równanie diofantyczne ax + by = c
DiophantineSolution solve_diophantine_recursive(int a, int b, int c);
DiophantineSolution solve_diophantine_loop(int a, int b, int c);
