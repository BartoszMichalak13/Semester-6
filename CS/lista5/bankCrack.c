/*
Identyfikacja Banku po Numerze Konta
PKO BP
	1020
Citi Handlowy
	1030
ING Bank Śląski
	1050
Bank BPH
	1060
mBank
	1140
Millennium Bank
	1160
Bank Pekao
	1240
Bank Pocztowy
	1320
Eurobank
	1470
Bank Ochrony Środowiska
	1540
Plus Bank
	1680
Raiffeisen Polbank
	1750
Nest Bank
	1870
Deutsche Bank
	1910
Credit Agricole
	1940
Idea Bank
	1950
BNP Paribas
	2030
Santander Bank Polska
	2120
Santander Consumer Bank
	2120
Volkswagen Bank
	2130
Toyota Bank
	2160
VeloBank
	2480
Alior Bank
	2490
*/

/*
same key, same data len, so S is always the same
*/

#include <stdint.h>
#include "head1.h"

#define MAX_CIPHERTEXTS 10
#define CIPHERTEXT_LENGTH 26 // Length of bank account number in bytes

void xor_strings(unsigned char *s1, unsigned char *s2, unsigned char *result, int length) {
  for (int i = 0; i < length; i++) {
    result[i] = s1[i] ^ s2[i];
  }
}

// int main(int argc, char* argv[argc + 1]) {
int bankCrack(\
      unsigned char* key,\
      const unsigned short BankNum,\
      const unsigned short AccPerBank) {
  // const short BankNum = 5;
  // const short AccPerBank = 10;

  unsigned char **accounts = malloc(BankNum * AccPerBank * sizeof(unsigned char*));
  if (accounts == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return EXIT_FAILURE;
  }

  // Allocate memory for each row
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    accounts[i] = malloc((ACCLEN + 1) * sizeof(unsigned char));
    if (accounts[i] == NULL) {
      fprintf(stderr, "Memory allocation failed for row %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(accounts[j]);
      }
      free(accounts);
      return EXIT_FAILURE;
    }
  }
  //WE KNOW THAT FOR COMMERCIAL BANKS acc[6] IS ALWAYS 0
  /*
  i = 6
  j = (S[1] + S[2] + S[3] + S[4] + S[5] + S[6]) % 256
  S[(S[i] + S[j]) % ASCII_MAX] = 
  */

  // note that: strlen((char *)accounts[0]) = ACCLEN
  generate_bank_accounts(BankNum, AccPerBank, &accounts);
  printf("in main \n");
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    printf("%s\n", accounts[i]);
  }
  //encrypt accounts
  unsigned char S[ASCII_MAX];
  for (size_t i = 0; i < BankNum * AccPerBank; ++i) {
    rc4Init(S, key, strlen((char *)key));
    rc4Crypt(S, accounts[i], ACCLEN);
  }
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    // printf("%s\n", accounts[i]);
    printHex(accounts[i], ACCLEN+1);
  }
  //note:: last 2 zeros of each res are '\0'
  printf("XORs: \n");
  for (short i = 0; i < BankNum * AccPerBank - 1; ++i) {
    unsigned char res[ACCLEN + 1];
    for (short j = 0; j < ACCLEN + 1; ++j) {
      res[j] = (unsigned char)(accounts[i][j] ^ accounts[i+1][j]);
    }
    res[ACCLEN] = '\0';
    printf("XOR "); 
    printHex(accounts[i], ACCLEN+1);
    printf("and "); 
    printHex(accounts[i+1], ACCLEN+1);
    printf("    ");
    printHex(res, ACCLEN+1);
    printf("\n");


    unsigned short accArr[ACCLEN];
    // string_to_int_array(accArr, ACCLEN, res);
    for (short j = 0; j < ACCLEN; ++j) {
      accArr[j] = (unsigned short) res[j];
    }
    int k = calculate_checksum(accArr);

    printf("accArr[%d] = ", i);
    for (short j = 0; j < ACCLEN; ++j) {
      printf("%d ", accArr[j]);
    }
    printf("\nk = %d\n", k);
  }
  // check this for later
  // for (short i = 0; i < BankNum * AccPerBank; ++i) {
  //   unsigned short accArr[ACCLEN];
  //   string_to_int_array(accArr, ACCLEN, accounts[i]);
  //   int k = calculate_checksum(accArr);

  //   printf("accArr[%d] = ", i);
  //   for (short j = 0; j < ACCLEN; ++j) {
  //     printf("%d ", accArr[j]);
  //   }
  //   printf("\nk = %d\n", k);
  //   //accArr[9] = k
  // }

  //XORY BO SIE KLUCZE REDUKUJE DEBILU
  //k = accARR[9] ^= S[(S[i] + S[j]) % ASCII_MAX];
  //i = 9 
  free(accounts);
  return EXIT_SUCCESS;
}

