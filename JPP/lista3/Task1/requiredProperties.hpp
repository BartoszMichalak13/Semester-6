#ifndef REQPROP
#define REQPROP
#include <concepts> //concepts
#include <random> //mt19937
#include <cstdint> //uint64_t

template<typename T>
concept HasGetP = requires (T a) {
  {a.getP()} -> std::same_as<uint64_t>;
};

template<typename T>
concept HasValue = requires (T a) {
  {a.value} -> std::same_as<uint64_t&>;
};

template<typename T, typename U = uint64_t>
concept HasConstructorWithUint64Param = requires(U u) {
    { T(u) } -> std::same_as<T>;
};

template<typename T>
concept IsGFlike = HasGetP<T> && HasValue<T> && HasConstructorWithUint64Param<T>;

#endif
