#include "head1.h"

/*
Potentially unused
*/
void saveToFile(\
      unsigned char *data,\
      int length,\
      const char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file != NULL) {
    fwrite(data, 1, length, file);
    fclose(file);
  } else {
    perror("Error opening file for writing");
  }
}

void printHex(unsigned char *data, size_t length) {
  for (size_t i = 0; i < length; i++) {
    printf("%02x", data[i]);
  }
  printf("\n");
}

inline void printUsage(void) {
  printf("Usage to compare a message encrypted by two keys: 1 <key1> <key2> <message>\n");
  printf("Usage to compare two messages encrypted by a key: 2 <key1> <key2> <message1> <message2>\n");
  printf("Usage to crack rc4: 3 <key> <number of banks> <number of accounts per bank>\n");
}
