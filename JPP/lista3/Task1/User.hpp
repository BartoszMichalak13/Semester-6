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

      // const_cast<uint64_t*>(secret.p)

      std::uniform_int_distribution<uint64_t> dis(1,p-1); 
      T gf = T(p);
      // std::cout << "p " << p << std::endl;
      gf.value = dis(gen);
      secret = gf;
      generator = dhs.power(dhs.getGenerator(), secret.value);
      // key = dhs.power(dhs.getGenerator(), secret.value);
      key.value = 0;
      // std::cout << std::endl;
      std::cout << "secret.value " << secret.value <<std::endl;
      std::cout << "generator " << generator.value <<std::endl;
      std::cout << "dhs.getGenerator() " << dhs.getGenerator() <<std::endl;
      // std::cout << std::endl;
    };
    
    T getPublicKey() {
      return generator;
      // return key;
    }

    //remove later
    T PRIVATEKEY() {
      return key;
      // return key;
    }
    
    void setKey(T& a) {
      std::cout << std::endl;
      std::cout << "a " << a <<std::endl;
      std::cout << "secret.value " << secret.value <<std::endl;
      std::cout << "generator " << generator <<std::endl;
      std::cout << "generator*secret.value " << generator*secret.value <<std::endl;
      std::cout << "a" << a <<std::endl;
      std::cout << "a*secret.value " << a*secret.value <<std::endl;
  
      key = DHSetup<T>::power(a, secret.value);
      std::cout << "key " << key <<std::endl;
      std::cout << std::endl;

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