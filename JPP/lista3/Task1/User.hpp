#ifndef USRHDR
#define USRHDR
// #include <concepts> //concepts
// #include <cstdint> //uint64_t
// #include <cstring> //memset
// #include <vector> //vector
// #include <random> //mt19937
#include <stdexcept>
#include "DHSetup.hpp"
#include "requiredProperties.hpp"
#include <iostream>

template<IsGFlike T>
class User {
  private:
    T secret;
    T key;

    T generator;
  public:
    User(DHSetup<T>& dhs): \
        secret(T(dhs.getP())),\
        key(T(dhs.getP())),\
        generator(T(dhs.getP())) {

      std::random_device rd;
      std::mt19937 gen(rd());
      uint64_t p = dhs.getP();

      std::uniform_int_distribution<uint64_t> dis(1,p-1); 
      T gf = T(p);
      gf.value = dis(gen);
      secret = gf;
      generator = dhs.power(dhs.getGenerator(), secret.value);
      key.value = 0;
    };
    
    T getPublicKey() {
      return generator;
    }

    //remove later
    T PRIVATEKEY() {
      return key;
    }
    
    void setKey(T& a) {
      key = DHSetup<T>::power(a, secret.value);
    }

    T encrypt(T m) {
      if (!key) {
        throw std::logic_error("Key not set");
      }
      return m * key;
    }

    T decrypt(T c) {
      if (!key) {
        throw std::logic_error("Key not set");
      }
      return c / key;
    }
};

#endif