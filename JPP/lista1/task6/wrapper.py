# wrapper.py

import sys
import ctypes
from ctypes import c_int, Structure
import subprocess

def compile_shared_library():
    # Command to compile library_whole.c into a shared library
    compile_command = ['gcc', '-shared', '-o', 'library_whole.so', '-fPIC', '../task1/library_whole.c']
    
    # Run the compilation command
    subprocess.run(compile_command, check=True)

# Call the function to compile the shared library
compile_shared_library()

# Load the shared library (we pass full path - not recommended)
lib = ctypes.CDLL('./library_whole.so')  # Adjust the path accordingly

# Define the DiophantineSolution structure
class DiophantineSolution(Structure):
    _fields_ = [("x", c_int), ("y", c_int)]

# Define the function prototypes
solve_diophantine_recursive = lib.solve_diophantine_recursive
solve_diophantine_recursive.argtypes = [c_int, c_int, c_int]
solve_diophantine_recursive.restype = DiophantineSolution

solve_diophantine_loop = lib.solve_diophantine_loop
solve_diophantine_loop.argtypes = [c_int, c_int, c_int]
solve_diophantine_loop.restype = DiophantineSolution

factorial_recursive = lib.factorial_recursive
factorial_recursive.argtypes = [c_int]
factorial_recursive.restype = c_int

factorial_loop = lib.factorial_loop
factorial_loop.argtypes = [c_int]
factorial_loop.restype = c_int

gcd_recursive = lib.gcd_recursive
gcd_recursive.argtypes = [c_int, c_int]
gcd_recursive.restype = c_int

gcd_loop = lib.gcd_loop
gcd_loop.argtypes = [c_int, c_int]
gcd_loop.restype = c_int

# Test the functiondef main():
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

    solution_loop = solve_diophantine_loop(a, b, c)
    print(f"Solution_loop to {a}x + {b}y = {c} is x = {solution_loop.x}, y = {solution_loop.y}")
    solution_recursive = solve_diophantine_recursive(a, b, c)
    print(f"Solution_recursive to {a}x + {b}y = {c} is x = {solution_recursive.x}, y = {solution_recursive.y}")

if __name__ == "__main__":
    main()