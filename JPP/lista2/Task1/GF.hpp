#ifndef GFHEADER
#define GFHEADER
#include <cmath>
#include <exception>
#include <cstdint>
#include <iostream>
#include <typeinfo>

class GF {
  private:
    const uint64_t p;
    uint64_t modPow(GF gf, uint64_t exp); 
  public:
    friend std::ostream& operator<< (std::ostream &out, const GF &gf);
    friend std::istream& operator>> (std::istream &in, const GF &gf);
    uint64_t value;
    GF(uint64_t p);
    GF();
    uint64_t const getP(void);

    explicit operator bool() const;
    explicit operator int() const;
    explicit operator uint64_t() const;
    explicit operator float() const;
    explicit operator double() const;

    // what if two GFs have different p?
    GF operator+(GF const& obj);
    GF operator-(GF const& obj);
    GF operator*(GF const& obj);
    GF operator/(GF const& obj);
    void operator=(GF const& obj);
    void operator+=(GF const& obj);
    void operator-=(GF const& obj);
    void operator*=(GF const& obj);
    void operator/=(GF const& obj);
    bool operator==(GF const& obj);
    bool operator!=(GF const& obj);
    bool operator<=(GF const& obj);
    bool operator>=(GF const& obj);
    bool operator<(GF const& obj);
    bool operator>(GF const& obj);
    
};
#endif