#include <stdbool.h> // bool
#include <stdio.h> // printf
#include <stdlib.h> //exit success
#include "keyPair.h"

//since q and p are prime instead of Carmichael's totient func
//we use Euler's totient funct, but since they are prime
//for p it is equal p-1, so we only use this function for n
static size_t carmichaelTotientFunction(unsigned long long int const p) {

}

keyPair RSA() {

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

int main(int argc, char* argv[argc+1]) {
  static unsigned long long int const p,q;
  size_t ret;
  if (argc < 2) {
    printf("Error: to few arguments.\n \
    Usage should look like: ./<name> p q \n \
    Where p,q are primes.\n");
    return EXIT_FAILURE;
  } else {
    //handle ret?
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
  static unsigned long long int const n = p*q;

}
