# library_recursion.py

from typing import NamedTuple

class DiophantineSolution(NamedTuple):
    x: int
    y: int

def factorial(n: int) -> int:
    """
    Calculates the factorial of n using recursion.
    """
    if n < 0:
        return 0
    if n == 0:
        return 1
    return n * factorial(n - 1)

def gcd(a: int, b: int) -> int:
    """
    Calculates the greatest common divisor of two natural numbers, a and b, using recursion.
    """
    if b == 0:
        return a
    return gcd(b, a % b)

def solve_diophantine(a: int, b: int, c: int) -> DiophantineSolution:
    solution = DiophantineSolution(0, 0)
    
    if (c % gcd(a, b)) != 0:
        print(f"Solution doesn't exist as {c} is not multiple of gcd({a}, {b})")
        return DiophantineSolution(float('-inf'), float('-inf'))

    if b == 0:
        solution = DiophantineSolution(c // a, 0)
    else:
        d = solve_diophantine(b, a % b, c)
        solution = DiophantineSolution(d.y, d.x - (a // b) * d.y)

    return solution