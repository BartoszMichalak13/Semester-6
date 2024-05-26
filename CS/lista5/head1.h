#ifndef HEAD1
#define HEAD1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h> // sizet
#include <stdbool.h>
#define ASCII_MAX 256
#define ACCLEN 26

/*
rc4
*/
void swap(\
  unsigned char* a,\
  unsigned char* b);

void rc4Init(\
  unsigned char *S,\
  unsigned char *key,\
  size_t key_length);

void rc4Crypt(\
  unsigned char *S,\
  unsigned char *data,\
  size_t data_length);

void saveToFile(\
  unsigned char *data,\
  int length,\
  const char *filename);

void printHex(\
  unsigned char *data,\
  size_t length);

// inline void printUsage(void);
void printUsage(void);

/*
rc4KeyCompare
*/
int keyCompare(\
  unsigned char *key1,\
  unsigned char *key2,\
  unsigned char *plaintext);

/*
rc4KeyDetection
*/
bool detectSameKey(\
  unsigned char *C1,\
  size_t len1,\
  unsigned char *C2,\
size_t len2);
int keyDetect(\
  unsigned char *key1,\
  unsigned char *key2,\
  unsigned char *message1,\
  unsigned char *message2);

/*
accGen
*/ 
void generate_bank_accounts(\
  const short BankNum,\
  const short AccountPerBank,\
  unsigned char ***accountsPointer);
void int_array_to_string(\
  const unsigned short *int_array,\
  int length,\
  char *str);
void string_to_int_array(\
  unsigned short *int_array,\
  int length,\
  const unsigned char *str);
bool verify_check_digit(\
  const unsigned short *sort_code_with_check_digit);
short calculate_checksum(\
  const unsigned short *account);
short random_digit_short();

/*
bankCrack
*/
int bankCrack(\
      unsigned char* key,\
      const unsigned short BankNum,\
      const unsigned short AccPerBank);
void xor_strings(\
  unsigned char *s1,\
  unsigned char *s2,\
  unsigned char *result,\
  int length);
/*main*/
// int main(int argc, char*argv[argc+1]);

#endif
