#include <stdio.h>

/*
  Funkcja obliczająca silnię n!
  returns 0 if n < 0
*/
unsigned long long factorial(int n);

// Funkcja obliczająca największy wspólny dzielnik dwóch liczb naturalnych
int gcd(int a, int b);

// Struktura przechowująca rozwiązanie równania diofantycznego ax + by = c
typedef struct {
    int x;
    int y;
} DiophantineSolution;

// Funkcja rozwiązująca równanie diofantyczne ax + by = c
DiophantineSolution solve_diophantine(int a, int b, int c);
