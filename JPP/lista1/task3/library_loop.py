# library_loop.py

from typing import NamedTuple

class DiophantineSolution(NamedTuple):
    x: int
    y: int

def factorial(n: int) -> int:
    """
    Calculates the factorial of n using a loop.
    """
    if n < 0:
        return 0
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def gcd(a: int, b: int) -> int:
    """
    Calculates the greatest common divisor of two natural numbers, a and b, using a loop.
    """
    while b != 0:
        a, b = b, a % b
    return a

def solve_diophantine(a: int, b: int, c: int) -> DiophantineSolution:
    if (c % gcd(a, b)) != 0:
        print(f"Solution doesn't exist as {c} is not multiple of gcd({a}, {b})")
        return DiophantineSolution(float('-inf'), float('-inf'))

    # Extended Euclidean algorithm
    s, old_s = 0, 1
    r, old_r = b, a

    while r != 0:
        quotient = old_r // r
        old_r, r = r, old_r - quotient * r
        old_s, s = s, old_s - quotient * s

    bezout_t = (old_r - old_s * a) // b if b != 0 else 0
    return DiophantineSolution(old_s * int(c / gcd(a, b)), bezout_t * int(c / gcd(a, b)))
