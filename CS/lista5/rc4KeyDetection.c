#include "head1.h"
#define range 16
#define threshold 2
/*
based on hex output, desired threshold should be 
evaluated on around 16 bytes (first ones)

Note: similiraty in current state 22.44 19.05 
seems to be mostly connected not to keys but to messages
which may be somewhat expected

It may explain why this algorith was proved to be dangerous
in excel and word. Similar messages signed with it 
(especially those with similar begining have HUGE similarity count)

TODO: pisza cos o xorowaniu, 
1. zrob wyswietlanie binarne
2. zrob zliczanie takch samych bitow (LSH)
*/
bool detectSameKey(\
      unsigned char *C1,\
      size_t len1,\
      unsigned char *C2,\
      size_t len2) {
  size_t min_length = len1 < len2 ? len1 : len2;
  size_t similarity_count = 0;

  unsigned char *c1XORc2 = malloc(sizeof(unsigned char) * min_length);
  for (size_t i = 0; i < min_length; i++) {
  // for (size_t i = 0; i < range; i++) {'
    c1XORc2[i] = C1[i] ^ C2[i];

    if (C1[i] == C2[i]) {
      similarity_count++;
    }
  }
  printf("mlen %ld measured %ld/%d\n",min_length, similarity_count, threshold);
  printf("xor c1 and c2: ");
  printHex(c1XORc2, min_length);
  free(c1XORc2);
  return similarity_count > threshold;
}

int keyDetect(\
      unsigned char *key1,\
      unsigned char *key2,\
      unsigned char *message1,\
      unsigned char *message2) {


  //no need for s1,s2 as they are not modified globally
  unsigned char S1[ASCII_MAX];
  unsigned char S2[ASCII_MAX];
  size_t data_length = strlen((char *)message1);
  size_t data_length2 = strlen((char *)message2);
  unsigned char *data1 = malloc(data_length);
  unsigned char *data1m2 = malloc(data_length2);
  unsigned char *data2 = malloc(data_length);
  memcpy(data1, message1, data_length);
  memcpy(data1m2, message2, data_length);
  memcpy(data2, message1, data_length);

  printf("Original message1: %s\n", message1);

  // Encrypt message1 with key1
  rc4Init(S1, key1, strlen((char *)key1));
  rc4Crypt(S1, data1, data_length);
  printf("Ciphertext1 with key1: ");
  printHex(data1, data_length);

  // Encrypt message2 with key1
  rc4Init(S2, key1, strlen((char *)key1));
  rc4Crypt(S2, data1m2, data_length2);
  printf("Ciphertext2 with key1: ");
  printHex(data1m2, data_length2);;

  if(detectSameKey(data1, data_length, data1m2, data_length2)) {
    printf("%s encrypted with %s and %s encrypted with %s have similar keys\n", data1, key1, data1m2, key1);
  } else {
    printf("No similarity between keys\n");
  } 
  
  // // Decrypt with key1
  // rc4Init(S, key1, strlen((char *)key1));
  // rc4Crypt(S, data1, data_length);
  // printf("Decrypted with key1: %s\n", data1);

  // Encrypt with key2
  rc4Init(S1, key2, strlen((char *)key2));
  rc4Crypt(S1, data2, data_length);
  printf("Ciphertext1 with key2: ");
  printHex(data2, data_length);

  if(detectSameKey(data1, data_length, data2, data_length)) {
    printf("%s encrypted with %s and %s encrypted with %s have similar keys\n", data1, key1, data2, key2);
  } else {
    printf("No similarity between keys\n");
  } 
  // Decrypt with key2
  // rc4Init(S, key2, strlen((char *)key2));
  // rc4Crypt(S, data2, data_length);
  // printf("Decrypted with key2: %s\n", data2);

  free(data1);
  free(data1m2);
  free(data2);
  return EXIT_SUCCESS;
}