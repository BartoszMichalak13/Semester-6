#include "GF.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  uint64_t p;
  if (argc < 2) {
    p = 1234577;
  } else {
    p = atoi(argv[1]);
  }
  GF gf = GF(p);
  GF gf2 = GF(p);
  GF gf3 = GF(p);
  std::cout << "characteristic: " << gf.getP() << std::endl;
  gf.value = 25;
  gf2.value = 5;
  gf3 = gf + gf2;
  std::cout << gf.value << " + " << gf2.value << " = " << gf3.value << std::endl;
  gf3 = gf - gf2;
  std::cout << gf.value << " - " << gf2.value << " = " << gf3.value << std::endl;
  gf3 = gf * gf2;
  std::cout << gf.value << " * " << gf2.value << " = " << gf3.value << std::endl;
  gf3 = gf / gf2;
  std::cout << gf.value << " / " << gf2.value << " = " << gf3.value << std::endl;
  
  std::cout << (gf < gf2) << " " << (gf == gf2) << " " <<\
  (gf <= gf2) << " " << (gf >= gf2) << " " <<\
  (gf > gf2) << " " << (gf != gf2) << " " << std::endl; 

  std::cout << "gf3 " << gf3.value << std::endl;
  gf3 = gf;
  std::cout << "gf3 " << gf3.value << std::endl;
  gf3 += gf;
  std::cout << "gf3 " << gf3.value << std::endl;
  gf3 -= gf;
  std::cout << "gf3 " << gf3.value << std::endl;
  gf3 *= gf;
  std::cout << "gf3 " << gf3.value << std::endl;
  gf3 /= gf;
  std::cout << "gf3 " << gf3.value << std::endl;

  GF g4 = gf3;
  // std::cout << "test cin " << std::endl;
  // std::cin >> g4;
  // std::cout << "value " << g4 << std::endl;
  GF g5 = g4;
  GF g6 = g4;
  GF g7 = g4;
  GF g8 = g4;
  GF g9 = g4;

  std::cout << "bool " << typeid((bool)g5).name() << std::endl;
  std::cout << "bool " << (bool)g5 << std::endl;
  std::cout << "int " << typeid((int)g6).name() << std::endl;
  std::cout << "int " << (int)g6 << std::endl;
  std::cout << "uint64_t " << typeid((uint64_t)g7).name() << std::endl;
  std::cout << "uint64_t " << (uint64_t)g7 << std::endl;
  std::cout << "float " << typeid((float)g8).name() << std::endl;
  std::cout << "float " << (float)g8 << std::endl;
  std::cout << "double " << typeid((double)g9).name() << std::endl;
  std::cout << "double " << (double)g9 << std::endl;
  // std::cout << "bool " << typeid((bool)g5).name() << std::endl;
    GF a = GF(p);
    a.value = 5;
    GF b = GF(p);
    b.value = 1;
    std::cout << a << " b " << b << std::endl;
    std::cout << b/a << std::endl;
  try {
    gf3 /= 0;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
