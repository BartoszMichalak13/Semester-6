#include <time.h>
#include "head1.h"
// Some of bank identifiers - short
const short bank_ids_short[] = {
  1020, // PKO BP
  1030, // Citi Handlowy
  1050, // ING Bank Śląski
  1060, // Bank BPH
  1140  // mBank
};
// Generate a random digit - short
short random_digit_short() {
  return rand() % 10;
}

// Calculate checksum using the provided formula - short
short calculate_checksum(const unsigned short *account) {
  short weights[8] = {3, 9, 7, 1, 3, 9, 7, 1};
  int sum = 0;
  for (short i = 0; i < 7; i++) {
    sum += account[i+2] * weights[i];
  }
  sum %= 10;
  //sum + k = 0 = 10
  short k = (10 - sum) % 10;
  return k;
}

bool verify_check_digit(const unsigned short *sort_code_with_check_digit) {
  short weights[8] = {3, 9, 7, 1, 3, 9, 7, 1};
  int total_sum = 0;
  for (short i = 0; i < 8; i++) {
    total_sum += sort_code_with_check_digit[i+2] * weights[i];
  }
  return total_sum % 10 == 0;
}

// Convert integer array to string
void int_array_to_string(const unsigned short *int_array, int length, char *str) {
  for (int i = 0; i < length; i++) {
    str[i] = '0' + int_array[i];
  }
  str[length] = '\0';
}
// Convert string to integer array
void string_to_int_array(unsigned short *int_array, int length, const unsigned char *str) {
  for (int i = 0; i < length; i++) {
    int_array[i] = str[i] - '0';
  }
  // int_array[length] = '\0';
}
/*
TODO: check chyba dla 8 z banku
caly check to - pl + kk na koniec
pl = 2521
calculate mod 97 tak zeby bylo = 1
*/

// Generate bank account numbers
void generate_bank_accounts(\
      const short BankNum,\
      const short AccountPerBank,\
      unsigned char ***accountsPointer) {
  unsigned char **accounts = *(accountsPointer);
  unsigned short account[ACCLEN];
  for (short bank = 0; bank < BankNum; bank++) {
    for (short i = 0; i < AccountPerBank; i++) {
      // Copy bank identifier as an integer
      short bank_id = bank_ids_short[bank];
      account[2] = (bank_id / 1000) % 10;
      account[3] = (bank_id / 100) % 10;
      account[4] = (bank_id / 10) % 10;
      account[5] = bank_id % 10;

      // Generate random B-part
      for (short j = 6; j < ACCLEN; j++) {
        account[j] = random_digit_short();
      }
      short tmpAcc[29];
      for (short i = 0; i < ACCLEN - 2; ++i) {
        tmpAcc[i] = account[i+2];
      }
      tmpAcc[24] = 2;
      tmpAcc[25] = 5;
      tmpAcc[26] = 2;
      tmpAcc[27] = 1;

      size_t sum = 0;
      for (short i = 0; i < ACCLEN + 1; ++i) {
        size_t value = tmpAcc[i];
        for (short j = i; j < ACCLEN + 1; ++j) {
          value *= 10;
        }
        sum += value;
      }
      sum %= 97;
      //sum + kk = 1 = 98
      short kk = 98 - sum;
      account[0] = (kk - (kk % 10)) / 10;
      account[1] = kk % 10;

      // Calculate checksum
      short checksum = calculate_checksum(account);
      account[9] = checksum;
      printf("verified = %d\n", verify_check_digit(account));

      char accStr[ACCLEN + 1];
      // Convert integer array to string for printing
      int_array_to_string(account, ACCLEN, accStr);
      // Print the generated account number
      printf("Bank %d Account %d: ", bank + 1, i + 1);
      for (short k = 0; k < ACCLEN; k++) {
        printf("%d", account[k]);
      }
      printf("\n");
      printf("Bank %d Account %d: ", bank + 1, i + 1);
      printf("%s", accStr);
      printf("\n");
      printf("bank*AccountPerBank + i = %d\n", bank*AccountPerBank + i);
      for (short k = 0; k < ACCLEN; k++) {
        accounts[bank*AccountPerBank + i][k] = accStr[k];
      }
      accounts[bank*AccountPerBank + i][ACCLEN] = '\0';
      printf("BANK %d Account %d: ", bank + 1, i + 1);
      printf("%s", accStr);
      printf("\n");
      printf("BANK %d Account %d: ", bank + 1, i + 1);
      printf("%s", accounts[bank*AccountPerBank + i]);
      printf("\n");
      printf("checksum = %d\n",checksum);
    }
  }
}
