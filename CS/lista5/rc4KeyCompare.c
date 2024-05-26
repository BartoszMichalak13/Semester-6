#include "head1.h"

int keyCompare(\
      unsigned char *key1,\
      unsigned char *key2,\
      unsigned char *plaintext) {

  unsigned char S[ASCII_MAX];
  size_t data_length = strlen((char *)plaintext);
  unsigned char *data1 = malloc(data_length);
  unsigned char *data2 = malloc(data_length);
  memcpy(data1, plaintext, data_length);
  memcpy(data2, plaintext, data_length);

  printf("Original plaintext: %s\n", plaintext);

  // Encrypt with key1
  rc4Init(S, key1, strlen((char *)key1));
  rc4Crypt(S, data1, data_length);
  printf("Ciphertext with key1: ");
  printHex(data1, data_length);
  // printf("%s\n", data1);
  // saveToFile();

  // Decrypt with key1
  rc4Init(S, key1, strlen((char *)key1));
  rc4Crypt(S, data1, data_length);
  printf("Decrypted with key1: %s\n", data1);

  // Encrypt with key2
  rc4Init(S, key2, strlen((char *)key2));
  rc4Crypt(S, data2, data_length);
  printf("Ciphertext with key2: ");
  printHex(data2, data_length);
  // printf("%s\n", data2);

  // Decrypt with key2
  rc4Init(S, key2, strlen((char *)key2));
  rc4Crypt(S, data2, data_length);
  printf("Decrypted with key2: %s\n", data2);

  free(data1);
  free(data2);
  return EXIT_SUCCESS;
}