# test.py

import sys

from library_loop import factorial as factorial_loop
from library_loop import gcd as gcd_loop
from library_loop import solve_diophantine as solve_diophantine_loop

from library_recursive import factorial as factorial_recursive
from library_recursive import gcd as gcd_recursive
from library_recursive import solve_diophantine as solve_diophantine_recursive

def main():
        
    if len(sys.argv) != 4:
        print("Usage: python main.py <a> <b> <c>")
        return
    
    try:
        a = int(sys.argv[1])
        b = int(sys.argv[2])
        c = int(sys.argv[3])
    except ValueError:
        print("Invalid input. Please provide integers for a, b, and c.")
        return
    
    print(f"Factorial_loop of {c} is {factorial_loop(c)}")
    print(f"Factorial_recursive of {c} is {factorial_recursive(c)}")

    print(f"GCD_loop of {a} and {b} is {gcd_loop(a, b)}")
    print(f"GCD_recursive of {a} and {b} is {gcd_recursive(a, b)}")

    solution = solve_diophantine_loop(a, b, c)
    print(f"Solution_loop to {a}x + {b}y = {c} is x = {solution[0]}, y = {solution[1]}")
    solution = solve_diophantine_recursive(a, b, c)
    print(f"Solution_recursive to {a}x + {b}y = {c} is x = {solution[0]}, y = {solution[1]}")

if __name__ == "__main__":
    main()