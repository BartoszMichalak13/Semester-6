from GF import GF
# Example usage:
if __name__ == "__main__":
    # Creating instances of GF
    a = GF()  # GF with prime modulus 7 and value 5
    b = GF()  # GF with prime modulus 7 and value 3

    a.setValue(25)
    b.setValue(5)
    # Operations
    print("a + b =", a + b)  # Addition
    print("a - b =", a - b)  # Subtraction
    print("a * b =", a * b)  # Multiplication
    print("a / b =", a / b)  # Division
    print("a == b is", a == b)  # Equality comparison
    print("a != b is", a != b)  # Inequality comparison
    print("a < b is", a < b)  # Less than comparison
    print("a <= b is", a <= b)  # Less than or equal to comparison
    print("a > b is", a > b)  # Greater than comparison
    print("a >= b is", a >= b)  # Greater than or equal to comparison
    a += b  # In-place addition
    print("After a += b, a is", a)
    a -= b  # In-place addition
    print("After a -= b, a is", a)
    a *= b  # In-place addition
    print("After a *= b, a is", a)
    a /= b  # In-place addition
    print("After a /= b, a is", a)
    a /= b  # In-place addition
    print("After a /= b, a is", a)
    a /= b  # In-place addition
    print("After a /= b, a is", a)
    a /= b  # In-place addition
    print("After a /= b, a is", a)
    a /= b  # In-place addition
    print("After a /= b, a is", a)