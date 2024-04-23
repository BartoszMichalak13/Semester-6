#ifndef DHSHEADER
#define DHSHEADER
// #include <concepts> //concepts
#include <cstring> //memset
#include <vector> //vector
// #include "lista2/Task1/GF.hpp"
#include "requiredProperties.hpp"
//EXTRA: add more concepts, like contains addition etc.
#include <iostream>

template<IsGFlike T>
class DHSetup {
  private:
    T generator;
    uint64_t p;
    static std::vector<uint64_t> generate_primes(uint64_t const& n) {
      std::vector<uint64_t> primeVector;
      bool *prime = new bool[n + 1];
      memset(prime, true, sizeof(*(prime)));

      /*SieveOfEratosthenes*/
      for (uint64_t p = 2; p * p <= n; ++p) { 
        if (prime[p]) {
          for (uint64_t i = p * p; i <= n; i += p) {
            prime[i] = false;
          }
          primeVector.push_back(p);
        }
      }
      return primeVector;
    }

    [[nodiscard]] bool check_generator(T& canditate, uint64_t& p) {
      std::vector<uint64_t> const primes = generate_primes(p-1);
      // for (uint64_t i = 0; i < primes.size(); ++i) {
      for (uint64_t const& i : primes) {
        //check types in this if, they're a bit wild
        if (canditate * (p-1)/i == 1) {
          return false;
        }
      }
      return true;
    }

  public:

    DHSetup(T& a) : p(a.getP()), generator(a.getP()) {

      // gfInstance = a;

      // uint64_t p = a.getP();
      std::cout << "p " << p << std::endl;
      std::cout << "a.getP() " << a.getP() << std::endl;

      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<uint64_t> dis(1,p-1);
      // std::uniform_int_distribution<T> dis(1,p-1);
      T gf = T(p);
      gf.value = dis(gen);
      // T candidate = dis(gen);
      T candidate = gf;
      while (!check_generator(candidate, p)) {
        gf.value = dis(gen);
        // candidate = dis(gen);
        candidate = gf;
      }
      generator = candidate;
    };

    uint64_t getP() {
      return p;
    }

    T getGenerator() {
      return generator;
    }

    static T power(T a, unsigned long b) {
      // std::cout  << "A p " << a.getP() << std::endl;
        if (b == 1) {
          return a;
        }
        if (!(b % 2)) {
          if (!b) { // b == 0, should we even handle this?
            T one = T(a.getP());
            one.value = 1;
            return one;
          }
          T tmpA = T(a.getP());
          tmpA = a*a;
          return power(tmpA, b/2);
        } else {
          T tmpA = T(a.getP());
          tmpA = a*a;
          T tmpA2 = T(a.getP());
          tmpA2 = power(tmpA, (b-1)/2);
          tmpA2 *= a;
          return tmpA2; //GF * GF should already have modulo operation
        }
    }
};

#endif