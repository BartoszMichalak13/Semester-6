#include "GF.hpp"

//TODO dodaj warunki na rownosc charakterystk
// oraz wiecej wyjatkow
  // TODO dec, inc, mul and div, what if value not set?

uint64_t GF::modPow(GF gf, uint64_t exp) {
  if (exp == 0) {
    return 1;
  }
  uint64_t prev_gf = 1;
  const uint64_t gf_val = gf.value;
  while (exp > 0) {
    prev_gf *= gf_val; 
    prev_gf %= p;
    --exp;
  }
  return prev_gf;
}
GF::GF(uint64_t p) : p(p) {}
GF::GF() : p(1234577){}
uint64_t const GF::getP(void) {
  return p;
}

GF::operator bool() const {
  return value != 0;
}
GF::operator int() const {
  return static_cast<int>(value);
}
GF::operator uint64_t() const {
  return static_cast<uint64_t>(value);
}
GF::operator float() const {
  return static_cast<float>(value);
}
GF::operator double() const {
  return static_cast<double>(value);
}

// what if two GFs have different p?
GF GF::operator+(GF const& obj) {
  GF gf;
  gf.value = (value + obj.value) % p;
  return gf;
}
GF GF::operator-(GF const& obj) {
  GF gf;
  gf.value = (value - obj.value) % p;
  return gf;
}
GF GF::operator*(GF const& obj) {
  GF gf;
  gf.value = (value * obj.value) % p;
  return gf;
}
GF GF::operator/(GF const& obj) {
  if (obj.value == 0) {
    throw std::invalid_argument("Division by zero");
  }
  GF gf;
  gf.value = (value * modPow(obj,p-2)) % p;
  return gf;
}

void GF::operator=(GF const& obj) {
  value = obj.value;
}
void GF::operator+=(GF const& obj) {
  value = (value + obj.value) % p;
}
void GF::operator-=(GF const& obj) {
  value = (value - obj.value) % p;
}
void GF::operator*=(GF const& obj) {
  value = (value * obj.value) % p;
}
void GF::operator/=(GF const& obj) {
  if (obj.value == 0) {
    throw std::invalid_argument("Division by zero");
  }
  value = (value * modPow(obj,p-2)) % p;
}

bool GF::operator==(GF const& obj) {
  return (value == obj.value);
}
bool GF::operator!=(GF const& obj) {
  return (value != obj.value);
}
bool GF::operator<=(GF const& obj) {
  return (value <= obj.value);
}
bool GF::operator>=(GF const& obj) {
  return (value >= obj.value);
}
bool GF::operator<(GF const& obj) {
  return (value < obj.value);
}
bool GF::operator>(GF const& obj) {
  return (value > obj.value);
}
std::ostream& operator<< (std::ostream &out, const GF &gf) {
  out << gf.value;
  return out;
}
std::istream& operator>> (std::istream &in, GF &gf) {
  in >> gf.value;
  return in; 
}