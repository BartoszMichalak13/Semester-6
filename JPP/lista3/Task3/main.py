import random
import numpy as np
import sys
sys.path.append('/home/bartek/Desktop/sem6/Semester-6/JPP/lista2/Task3/')  # Add the directory containing GF.py to the Python path
from GF import GF

class DHSetup:
    @staticmethod
    def generate_primes(n):
        sieve = np.ones(n + 1, dtype=bool)
        sieve[:2] = False
        for i in range(2, int(n**0.5) + 1):
            if sieve[i]:
                sieve[i*i:n+1:i] = False
        return np.nonzero(sieve)[0]

    @staticmethod
    def check_generator(candidate, p):
        print("hello")

        primes = DHSetup.generate_primes(p - 1)
        for i in primes:
            if candidate.value * (p - 1) // i == 1:
                return False
        return True

    def __init__(self, a):
        self.p = a.getP()
        generator = GF(self.p)
        i = 0
        while True:
            print(i)
            i += 1
            gf = GF(self.p)
            gf.value = random.randint(1, self.p - 1)
            candidate = GF(self.p)
            print("in")

            candidate.value = gf.value
            if DHSetup.check_generator(candidate, self.p):
                print("inin")
                generator = candidate
                break
        self.generator = generator
        print("out")
        
    def getP(self):
        return self.p

    def getGenerator(self):
        return self.generator

    @staticmethod
    def power(a, b):
        if b == 1:
            return a
        if b % 2 == 0:
            tmpA = a * a
            return DHSetup.power(tmpA, b // 2)
        else:
            tmpA = a * a
            tmpA2 = DHSetup.power(tmpA, (b - 1) // 2)
            tmpA2 *= a
            return tmpA2

class User:
    def __init__(self, dhs):
        self.secret = GF(dhs.getP())
        self.key = GF(dhs.getP())
        self.generator = GF(dhs.getP())

        p = dhs.getP()
        gf = GF(p)
        gf.value = random.randint(1, p - 1)
        self.secret = gf
        self.generator = dhs.power(dhs.getGenerator(), self.secret.value)
        self.key.value = 0

    def getPublicKey(self):
        return self.generator

    def setKey(self, a):
        self.key = DHSetup.power(a, self.secret.value)

    def encrypt(self, m):
        if not self.key:
            raise ValueError("Key not set")
        return m * self.key

    def decrypt(self, c):
        if not self.key:
            raise ValueError("Key not set")
        return c / self.key

# Example usage
def main():
    p = 1234567891
    print("all ok\n")
    gf = GF(p,12)
    print("all ok\n")

    # Creating DHSetup object for a field with characteristic 1234567891
    dh_setup = DHSetup(gf)  
    print("all ok\n")

    # Creating two users
    alice = User(dh_setup)
    bob = User(dh_setup)
    print("all ok\n")

    # Getting public keys
    alice_public_key = alice.getPublicKey()
    bob_public_key = bob.getPublicKey()
    print("all ok\n")

    # Exchanging public keys
    alice.setKey(bob_public_key)
    bob.setKey(alice_public_key)
    print("all ok\n")

    # Test encryption and decryption
    plaintext = GF(p)
    plaintext.value = 42
    encrypted = alice.encrypt(plaintext)
    decrypted = bob.decrypt(encrypted)

    print("\nPlaintext:", plaintext)
    print("Encrypted:", encrypted)
    print("Decrypted:", decrypted)

if __name__ == "__main__":
    main()