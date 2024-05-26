#include <stdbool.h> // bool
#include <stdio.h> // printf
#include <stdlib.h> //exit success
#include <math.h> //floor
#include <time.h> //rand
#include "Keys.h"

#define TYPICAL_E 65537

//TODO: SIEVE DOESNT MAXIMAL PRIME
// GCD EXTENDED doesnt WORK PROPERLY SEE WHY


static unsigned long long int gcd(\
      unsigned long long int a,\
      unsigned long long int b) {
  while(b) {
    unsigned long long int const r = b;
    b = a % b;
    a = r;
  }
  return a;
}
static unsigned long long int lcm(\
      unsigned long long int const p,\
      unsigned long long int const q) {
  return p*q/gcd(p,q);
}

unsigned long long int lecturesPow(\
      unsigned long long int base,\
      unsigned long long int exp, 
      unsigned long long int n) {
  unsigned long long int y = base;
  for (unsigned long long int i = 1; i < exp; i++) {
    y = y*base % n;
    // printf("i %llu, exp %llu\n",i, exp);
  }
  return y;
}

void lecturesAlg(\
      unsigned long int n,\
      unsigned long long int e,\
      unsigned long long int d,
      long long int *p,
      long long int *q) {
        
  unsigned long long int kphi = d*e - 1;
  unsigned long long int t = kphi;

  while (t%2 == 0) {
    t = floor(t/2);
  }
  
  unsigned long long int a = 2;
  // while (a < 500) {
    unsigned long long int k = t;
    while (k < kphi) {
      unsigned long long int x = lecturesPow(a,k,n);
      printf("k %llu, a %llu \n", k, a);
      if (x != t && x != (n-1) && ((x * x) % n) == 1) {
        *p = gcd(x-1,n);
        break;
      }
      k = k * 2;
    }
    // a = a + 2;
  // }
  *q = n/(*p);
}

// Function to find the modular inverse of 'a' modulo 'm' 
//using the Extended Euclidean Algorithm
int modInverse(\
      long long int a,\
      long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;

  if (m == 1)
    return 0;

  while (a > 1) {
    // q is quotient
    long long int q = a / m;
    long long int t = m;

    // m is remainder now, process same as Euclid's algo
    m = a % m;
    a = t;
    t = y;

    // Update y and x
    y = x - q * y;
    x = t;
  }

  // Make x positive
  if (x < 0)
    x += m0;

  return x;
}

//because we have info about what n,p,q are we know that:
//lambda(n) = lcm(lambda(p),lambda(q)) = lcm(p-1,q-1)
static size_t OptimizedCarmichaelTotientFunction(\
      unsigned long long int const p,
      unsigned long long int const q) {
  return lcm(p-1,q-1);
}

static bool checkIfPrime(unsigned long long int const p) {
  if (p == 1) {
    return false;
  }
  for (unsigned long long int i = 2; i*i <= p; ++i) {
    if (p % i == 0) {
      return false;
    }
  }
  return true;
}

unsigned long long int randomE(\
      unsigned long long int lowerB,\
      unsigned long long int upperB) {
  
  unsigned long long int e = lowerB + rand() % (upperB - lowerB + 1);
  while (gcd(e,upperB) != 1) {
    e = lowerB + rand() % (upperB - lowerB + 1);
  }
  return e;
}

// int main(int argc, char* argv[argc+1]) {
int main(int argc, char** argv) {
  srand(time(NULL));

  static unsigned long long int p,q;
  if (argc < 2) {
    printf("Error: to few arguments.\n \
    Usage should look like: ./<name> p q \n \
    Where p,q are primes.\n");
    return EXIT_FAILURE;
  } else {
    //handle ret?
    size_t ret;
    ret = sscanf(argv[1], "%llu", &p);
    ret = sscanf(argv[2], "%llu", &q);
  }
  if (!checkIfPrime(p)) {
    printf("p is not prime.\n");
    return EXIT_FAILURE;
  }
  if (!checkIfPrime(q)) {
    printf("q is not prime.\n");
    return EXIT_FAILURE;
  }
  //check for overflow?
  unsigned long long int const n = p*q;
  unsigned long long int const lamdaN = OptimizedCarmichaelTotientFunction(p,q);
  unsigned long long int e;

  printf("lambdaN %llu\n", lamdaN);

  e = randomE(2,lamdaN);
  unsigned long long int x = modInverse(e,lamdaN); 

  Key pkA = (Key){ .n = n, .e = e };
  Key skA = (Key){ .n = n, .e = x };

  e = randomE(2,lamdaN);
  x = modInverse(e,lamdaN); 

  Key pkB = (Key){ .n = n, .e = e };
  Key skB = (Key){ .n = n, .e = x };

  printf("pkA: (%llu,%llu);\n skA: (%llu,%llu);\n", pkA.n, pkA.e, skA.n, skA.e);
  printf("pkB: (%llu,%llu);\n skB: (%llu,%llu);\n", pkB.n, pkB.e, skB.n, skB.e);

  //find p and q 

  long long int pR,qR;
  lecturesAlg(n,e,x,&pR,&qR);

  printf("p %lld, q %lld\n", pR, qR);
  
  unsigned long long int const lamdaNR = OptimizedCarmichaelTotientFunction(qR,pR);
  printf("lambdaNR %llu\n", lamdaNR);

  // unsigned long long int xR = modInverse(e,lamdaNR); 
  unsigned long long int xR = modInverse(e,lamdaN); 
  // xR = modInverse(e,lamdaNR); 

  Key pkBR = (Key){ .n = n, .e = e };
  Key skBR = (Key){ .n = n, .e = xR };
  printf("pkBR: (%llu,%llu);\n skBR: (%llu,%llu);\n", pkBR.n, pkBR.e, skBR.n, skBR.e);

  return EXIT_SUCCESS;
}
