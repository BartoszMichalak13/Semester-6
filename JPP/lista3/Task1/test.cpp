#include "DHSetup.hpp"
#include "User.hpp"
#include "../../lista2/Task1/GF.hpp"

int main(int argc, char *argv[]) {
  uint64_t p;
  if (argc < 2) {
    p = 1234567891;
  } else {
    p = atoi(argv[1]);
  }
  GF gf = GF(p);
  gf.value = 12;


  // Stworzenie obiektu DHSetup dla ciała o charakterystyce 1234567891
  DHSetup<GF> dhSetup(gf);// = DHSetup(gf);

  // Tworzenie dwóch użytkowników
  User<GF> alice(dhSetup);
  User<GF> bob(dhSetup);

  // Uzyskanie kluczy publicznych
  GF alicePublicKey = alice.getPublicKey();
  GF bobPublicKey = bob.getPublicKey();

  // Wymiana kluczy publicznych
  alice.setKey(bobPublicKey);
  bob.setKey(alicePublicKey);

  // Test szyfrowania i deszyfrowania
  GF plaintext = GF(p);
  plaintext.value = 42;
  GF encrypted = GF(p);
  encrypted = alice.encrypt(plaintext);
  GF decrypted = GF(p);
  decrypted = bob.decrypt(encrypted);

  std::cout << std::endl;
  std::cout << "Plaintext: " << plaintext << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
  std::cout << std::endl;

  plaintext.value = 128422;
  encrypted = bob.encrypt(plaintext);
  decrypted = alice.decrypt(encrypted);

  std::cout << std::endl;
  std::cout << "Plaintext: " << plaintext << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
  std::cout << std::endl;

  plaintext.value = 128422;
  encrypted = alice.encrypt(plaintext);
  decrypted = bob.decrypt(encrypted);

  std::cout << std::endl;
  std::cout << "Plaintext: " << plaintext << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
  std::cout << std::endl;
  
  plaintext.value = 1752;
  encrypted = alice.encrypt(plaintext);
  decrypted = bob.decrypt(encrypted);

  std::cout << std::endl;
  std::cout << "Plaintext: " << plaintext << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
  std::cout << std::endl;

  plaintext.value = 15;
  encrypted = alice.encrypt(plaintext);
  decrypted = bob.decrypt(encrypted);

  std::cout << std::endl;
  std::cout << "Plaintext: " << plaintext << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
  std::cout << std::endl;

  plaintext.value = 12;
  encrypted = alice.encrypt(plaintext);
  decrypted = bob.decrypt(encrypted);

  std::cout << std::endl;
  std::cout << "Plaintext: " << plaintext << std::endl;
  std::cout << "Encrypted: " << encrypted << std::endl;
  std::cout << "Decrypted: " << decrypted << std::endl;
  std::cout << std::endl;
  return EXIT_SUCCESS;
}