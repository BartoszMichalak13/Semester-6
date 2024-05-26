#include "head1.h"

inline void swap(\
      unsigned char* a,\
      unsigned char* b) {
  unsigned char tmp = *a;
  *a = *b;
  *b = tmp;
}
/*
Initializes S
*/
void rc4Init(\
    unsigned char *S,\
    unsigned char *key,\
    size_t key_length) {
  for (size_t i = 0; i < ASCII_MAX; i++) {
    S[i] = i;
  }
  size_t j = 0;
  for (size_t i = 0; i < ASCII_MAX; i++) {
    j = (j + S[i] + key[i % key_length]) % ASCII_MAX;
    swap(&S[i], &S[j]);
  }
}
/*
Encrypted message is returned in data
*/
void rc4Crypt(\
unsigned char *S,\
unsigned char *data,\
size_t data_length) {
  size_t i = 0, j = 0;
  for (size_t k = 0; k < data_length; k++) {
    i = (i + 1) % ASCII_MAX;
    j = (j + S[i]) % ASCII_MAX;
    swap(&S[i], &S[j]);
    data[k] ^= S[(S[i] + S[j]) % ASCII_MAX];
  }
}
