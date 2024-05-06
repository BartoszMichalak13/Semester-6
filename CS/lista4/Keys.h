typedef struct Key {
  unsigned long long int n, e;
} Key;

typedef struct KeyPair {
  Key pk, sk;
} KeyPair;
