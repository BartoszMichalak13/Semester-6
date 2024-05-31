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

bool calculateCC(short *a, short l, bool ***fp, bool printFlag) {
  
  short tmpAcc[28];
  for (short ii = 2; ii < ACCLEN; ++ii) {
    tmpAcc[ii-2] = a[ii];
  }
  tmpAcc[24] = 2;
  tmpAcc[25] = 5;
  tmpAcc[26] = 2;
  tmpAcc[27] = 1;

  size_t sum = 0;
  for (short ii = 0; ii < ACCLEN+  2; ++ii) {
    size_t value = tmpAcc[ii];
    for (short jjj = ii; jjj < ACCLEN + 2; ++jjj) {
      value *= 10;
    }
    // value *= 10000;
    sum += value;
  }
  // sum = sum + 2000 + 500 + 20 + 1; 
  sum %= 97;
  //sum + kk = 1 = 98
  short kk = 98 - sum;
  if (printFlag) {
    printf("kk: %d, fp[l][0][(kk - (kk mod 10)) / 10]: %d, fp[l][1][kk mod 10]: %d\n", kk, fp[l][0][(kk - (kk % 10)) / 10],fp[l][1][kk % 10] );
  }
  if (fp[l][0][(kk - (kk % 10)) / 10] &&
      fp[l][1][kk % 10]) {
    return true;
  } 
  return false;
}

void xor_strings(unsigned char *s1, unsigned char *s2, unsigned char *result, int length) {
  for (int i = 0; i < length; i++) {
    result[i] = s1[i] ^ s2[i];
  }
}
/*
  1   = (0,1)   (2,3)   (4,5)   (6,7)   (8,9)
  2   = (0,2)   (1,3)   (4,6)   (5,7)
  3   = (0,3)   (1,2)   (4,7)   (5,6)
  4   = (0,4)   (1,5)   (2,6)   (3,7)   
  5   = (0,5)   (1,4)   (2,7)   (3,6)
  6   = (0,6)   (1,7)   (2,4)   (3,5)
  7   = (0,7)   (1,6)   (2,5)   (3,4)
  8   = (0,8)   (1,9)
  9   = (0,9)   (1,8)
  10  = (2,8)   (3,9)
  11  = (2,9)   (3,8)
  12  = (4,8)   (5,9)
  13  = (4,9)   (5,8)
  14  = (6,8)   (7,9)
  15  = (6,9)   (7,8)

*/
void fillPossible(bool *arr, short num) {
  switch (num)
  {
  case 0:
    for (short i = 0; i < 10; ++i) {
      arr[i] = true;
    }
    break;
  case 1:
    for (short i = 0; i < 10; ++i) {
      // if (i != 1) {
        arr[i] = true;
      // }
    }
    break;
    
  case 2:
    arr[0] = true; arr[2] = true;
    arr[1] = true; arr[3] = true;
    arr[4] = true; arr[6] = true;
    arr[5] = true; arr[7] = true;
    break;
  case 3:
    arr[0] = true; arr[3] = true;
    arr[1] = true; arr[2] = true;
    arr[4] = true; arr[7] = true;
    arr[5] = true; arr[6] = true;
    break;
  case 4:
    arr[0] = true; arr[4] = true;
    arr[1] = true; arr[5] = true;
    arr[2] = true; arr[6] = true;
    arr[3] = true; arr[7] = true;
    break;
  case 5:
    arr[0] = true; arr[5] = true;
    arr[1] = true; arr[4] = true;
    arr[2] = true; arr[7] = true;
    arr[3] = true; arr[6] = true;
    break;
  case 6:
    arr[0] = true; arr[6] = true;
    arr[1] = true; arr[7] = true;
    arr[2] = true; arr[4] = true;
    arr[3] = true; arr[5] = true;
    break;
  case 7:
    arr[0] = true; arr[7] = true;
    arr[1] = true; arr[6] = true;
    arr[2] = true; arr[5] = true;
    arr[3] = true; arr[4] = true;
    break;

  case 8:
    arr[0] = true; arr[8] = true;
    arr[1] = true; arr[9] = true;
    break;
  case 9:
    arr[0] = true; arr[9] = true;
    arr[1] = true; arr[8] = true;
    break;

  case 10:
    arr[2] = true; arr[8] = true;
    arr[3] = true; arr[9] = true;
    break;
  case 11:
    arr[2] = true; arr[9] = true;
    arr[3] = true; arr[8] = true;
    break;

  case 12:
    arr[4] = true; arr[8] = true;
    arr[5] = true; arr[9] = true;
    break;
  case 13:
    arr[4] = true; arr[9] = true;
    arr[5] = true; arr[8] = true;
    break;

  case 14:
    arr[6] = true; arr[8] = true;
    arr[7] = true; arr[9] = true;
    break;
  case 15:
    arr[6] = true; arr[9] = true;
    arr[7] = true; arr[8] = true;
    break;

  default:
    fprintf(stderr, "Error in fillPossible %d\n", num);
    break;
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
    fprintf(stderr, "Memory for accounts allocation failed\n");
    return EXIT_FAILURE;
  }
  // Allocate memory for each row
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    accounts[i] = malloc((ACCLEN + 1) * sizeof(unsigned char));
    if (accounts[i] == NULL) {
      fprintf(stderr, "Memory for accounts allocation failed for row %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(accounts[j]);
      }
      free(accounts);
      return EXIT_FAILURE;
    }
  }

  unsigned char **plainAcccounts = malloc(BankNum * AccPerBank * sizeof(unsigned char*));
  if (plainAcccounts == NULL) {
    fprintf(stderr, "Memory for plainAcccounts allocation failed\n");
    return EXIT_FAILURE;
  }
  // Allocate memory for each row
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    plainAcccounts[i] = malloc((ACCLEN + 1) * sizeof(unsigned char));
    if (plainAcccounts[i] == NULL) {
      fprintf(stderr, "Memory for plainAcccounts allocation failed for row %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(plainAcccounts[j]);
      }
      free(plainAcccounts);
      return EXIT_FAILURE;
    }
  }
  
  // note that: strlen((char *)accounts[0]) = ACCLEN
  generate_bank_accounts(BankNum, AccPerBank, &accounts);
  
  printf("in main \n");
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    printf("%s\n", accounts[i]);
    for (short j = 0; j < ACCLEN+1; ++j) {
      plainAcccounts[i][j] = accounts[i][j];
    }
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

  /*

  XOR: 
  00 -> 0
  01 -> 1
  10 -> 1
  11 -> 0
  
  0   0000  0000
  1   0000  0001
  2   0000  0010
  3   0000  0011
  4   0000  0100
  5   0000  0101
  6   0000  0110
  7   0000  0111
  8   0000  1000
  9   0000  1001
  
  a - 10
  b - 11
  c - 12
  d - 13
  e - 14
  f - 15

  XOR:
  0 x = x
  1 1 = 0
  1 2 = 3   2 2 = 0
  1 3 = 2   2 3 = 1   3 3 = 0
  1 4 = 5   2 4 = 6   3 4 = 7   4 4 = 0
  1 5 = 4   2 5 = 7   3 5 = 6   4 5 = 1   5 5 = 0
  1 6 = 7   2 6 = 4   3 6 = 5   4 6 = 2   5 6 = 3   6 6 = 0
  1 7 = 6   2 7 = 5   3 7 = 4   4 7 = 3   5 7 = 2   6 7 = 1   7 7 = 0
  1 8 = 9   2 8 = a   3 8 = b   4 8 = c   5 8 = d   6 8 = e   7 8 = f   8 8 = 0
  1 9 = 8   2 9 = b   3 9 = a   4 9 = d   5 9 = c   6 9 = f   7 9 = e   8 9 = 1   9 9 = 0

  by value

  1   = (0,1)   (2,3)   (4,5)   (6,7)   (8,9)
  2   = (0,2)   (1,3)   (4,6)   (5,7)
  3   = (0,3)   (1,2)   (4,7)   (5,6)
  4   = (0,4)   (1,5)   (2,6)   (3,7)   
  5   = (0,5)   (1,4)   (2,7)   (3,6)
  6   = (0,6)   (1,7)   (2,4)   (3,5)
  7   = (0,7)   (1,6)   (2,5)   (3,4)
  8   = (0,8)   (1,9)
  9   = (0,9)   (1,8)
  10  = (2,8)   (3,9)
  11  = (2,9)   (3,8)
  12  = (4,8)   (5,9)
  13  = (4,9)   (5,8)
  14  = (6,8)   (7,9)
  15  = (6,9)   (7,8)

  */
  /*
  IDEA: do kazdej cyfry w ibanie daje tablice bool [10] gdzie
  true - mozliwa, false - nie mozliwa
  no i jak zostaje tylko jedno true to wiadomo co jest
  kwestia sprawdzania tych cyferek tak zeby pasowaly jeszcze 

  jezeli potrafimy odszywfrowac 1 to mozemy wszystkie
  else return za malo kont
  do it ACCLEN, +10 for final possibilities
  */
  //konta x konta x 26 x 10
  bool ****posibleNumbers = malloc(BankNum * AccPerBank * sizeof(bool***));
  if (posibleNumbers == NULL) {
    fprintf(stderr, "Memory for posibleNumbers allocation failed\n");
    return EXIT_FAILURE;
  }
  // Allocate memory for each account
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    posibleNumbers[i] = malloc(BankNum * AccPerBank * sizeof(bool**));
    if (posibleNumbers[i] == NULL) {
      fprintf(stderr, "Memory for posibleNumbers for each acc allocation failed for acc %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(posibleNumbers[j]);
      }
      free(posibleNumbers);
      return EXIT_FAILURE;
    }
    // Allocate memory for each row
    for (short ii = 0; ii < BankNum * AccPerBank; ++ii) {
      posibleNumbers[i][ii] = malloc((ACCLEN) * sizeof(bool*));
      if (posibleNumbers[i][ii] == NULL) {
        fprintf(stderr, "Memory for posibleNumbers allocation failed for row %d\n", ii);
        // Free previously allocated memory before exiting
        for (short j = 0; j < ii; ++j) {
          free(posibleNumbers[i][j]);
        }
        free(posibleNumbers[i]);
        for (short j = 0; j < i; ++j) {
          for (short jj = 0; jj < BankNum * AccPerBank; ++jj) {
            free(posibleNumbers[j][jj]);
          }
          free(posibleNumbers[j]);
        }
        free(posibleNumbers);
        return EXIT_FAILURE;
      }
      for (short iii = 0; iii < ACCLEN; ++iii) {
        posibleNumbers[i][ii][iii] = malloc(10 * sizeof(bool)); //place for each num
        if (posibleNumbers[i][ii][iii] == NULL) {
          fprintf(stderr, "Memory for posibleNumbers allocation failed for number %d\n", iii);
          // Free previously allocated memory before exiting
          for (short j = 0; j < iii; ++j) {
            free(posibleNumbers[i][ii][j]);
          }
          free(posibleNumbers[i][ii]);
          for (short j = 0; j < i; ++j) {
            for (short jj = 0; jj < BankNum * AccPerBank; ++jj) {
              for (short jjj = 0; jjj < ACCLEN; ++jjj) {
                free(posibleNumbers[j][jj][jjj]);
              }
              free(posibleNumbers[j][jj]);
            }
            free(posibleNumbers[j]);
          }
          free(posibleNumbers);
          return EXIT_FAILURE;
        }
      }
    }
  }

  //fill with false 
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < BankNum * AccPerBank; ++ii) {
      for (short iii = 0; iii < ACCLEN; ++iii) {
        for (short iiii = 0; iiii < 10; ++iiii) {
          posibleNumbers[i][ii][iii][iiii] = false;
        }
      }
    }
  }
  //konta x 26 x 10
  bool ***finalPossible = malloc(BankNum * AccPerBank * sizeof(bool**));
  // unsigned short ***results = malloc(BankNum * AccPerBank * sizeof(unsigned short**));
  if (finalPossible == NULL) {
    fprintf(stderr, "Memory for results allocation failed\n");
    return EXIT_FAILURE;
  }
  // Allocate memory for each account
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    finalPossible[i] = malloc(ACCLEN * sizeof(bool*));
    if (finalPossible[i] == NULL) {
      fprintf(stderr, "Memory for finalPossible for each acc allocation failed for acc %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(finalPossible[j]);
      }
      free(finalPossible);
      return EXIT_FAILURE;
    }
    // Allocate memory for each row
    for (short ii = 0; ii < ACCLEN; ++ii) {
      finalPossible[i][ii] = malloc((10) * sizeof(bool));
      if (finalPossible[i][ii] == NULL) {
        fprintf(stderr, "Memory for finalPossible allocation failed for row %d\n", ii);
        // Free previously allocated memory before exiting
        for (short j = 0; j < ii; ++j) {
          free(finalPossible[i][j]);
        }
        free(finalPossible[i]);
        for (short j = 0; j < i; ++j) {
          for (short jj = 0; jj < ACCLEN; ++jj) {
            free(finalPossible[j][jj]);
          }
          free(finalPossible[j]);
        }
        free(finalPossible);
        return EXIT_FAILURE;
      }
    }
  } 
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < ACCLEN; ++ii) {
      for (short iii = 0; iii < 10; ++iii) {
        finalPossible[i][ii][iii] = false;
      }
    }
  }

  //konta x 26 x 10
  bool ***finalPossible2 = malloc(BankNum * AccPerBank * sizeof(bool**));
  // unsigned short ***results = malloc(BankNum * AccPerBank * sizeof(unsigned short**));
  if (finalPossible2 == NULL) {
    fprintf(stderr, "Memory for results allocation failed\n");
    return EXIT_FAILURE;
  }
  // Allocate memory for each account
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    finalPossible2[i] = malloc(ACCLEN * sizeof(bool*));
    if (finalPossible2[i] == NULL) {
      fprintf(stderr, "Memory for finalPossible for each acc allocation failed for acc %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(finalPossible2[j]);
      }
      free(finalPossible2);
      return EXIT_FAILURE;
    }
    // Allocate memory for each row
    for (short ii = 0; ii < ACCLEN; ++ii) {
      finalPossible2[i][ii] = malloc((10) * sizeof(bool));
      if (finalPossible2[i][ii] == NULL) {
        fprintf(stderr, "Memory for finalPossible allocation failed for row %d\n", ii);
        // Free previously allocated memory before exiting
        for (short j = 0; j < ii; ++j) {
          free(finalPossible2[i][j]);
        }
        free(finalPossible2[i]);
        for (short j = 0; j < i; ++j) {
          for (short jj = 0; jj < ACCLEN; ++jj) {
            free(finalPossible2[j][jj]);
          }
          free(finalPossible2[j]);
        }
        free(finalPossible2);
        return EXIT_FAILURE;
      }
    }
  } 
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < ACCLEN; ++ii) {
      for (short iii = 0; iii < 10; ++iii) {
        finalPossible2[i][ii][iii] = false;
      }
    }
  }

  //konta x konta x 26
  unsigned short ***results = malloc(BankNum * AccPerBank * sizeof(unsigned short**));
  if (results == NULL) {
    fprintf(stderr, "Memory for results allocation failed\n");
    return EXIT_FAILURE;
  }
  // Allocate memory for each account
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    results[i] = malloc(BankNum * AccPerBank * sizeof(unsigned short*));
    if (results[i] == NULL) {
      fprintf(stderr, "Memory for results for each acc allocation failed for acc %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(results[j]);
      }
      free(results);
      return EXIT_FAILURE;
    }
    // Allocate memory for each row
    for (short ii = 0; ii < BankNum * AccPerBank; ++ii) {
      results[i][ii] = malloc((ACCLEN) * sizeof(short));
      if (results[i][ii] == NULL) {
        fprintf(stderr, "Memory for results allocation failed for row %d\n", ii);
        // Free previously allocated memory before exiting
        for (short j = 0; j < ii; ++j) {
          free(results[i][j]);
        }
        free(results[i]);
        for (short j = 0; j < i; ++j) {
          for (short jj = 0; jj < BankNum * AccPerBank; ++jj) {
            free(results[j][jj]);
          }
          free(results[j]);
        }
        free(results);
        return EXIT_FAILURE;
      }
    }
  } // i teraz mozna xorowac :)))

  //fill in results and possible numbers
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < BankNum * AccPerBank; ++ii) {
      if (ii != i) {
        for (short j = 0; j < ACCLEN; ++j) {
          unsigned short xoredVal = (unsigned short)(accounts[i][j] ^ accounts[(ii)%(BankNum * AccPerBank)][j]);
          results[i][ii][j] = xoredVal;
          fillPossible(posibleNumbers[i][ii][j],xoredVal);
        }
      }
    }
  }

  //THINK ABOUT LOGIC - HOW TO NARROW DOWN ALL POSSIBILIITES 
  //for given account check all numbers for all xors to see all posibilites
  //work okay-ish for all except AAAA AAAA
  short counter = 0;
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short iii = 0; iii < ACCLEN; ++iii) {
      bool nextXOR = false;
      for (short ii = 0; ii < BankNum * AccPerBank; ++ii) {
        if (i != ii && i != (ii+1)%(BankNum * AccPerBank)) {
          counter = 0;
          for (short iiii = 0; iiii < 10; ++iiii) {
            //jezeli tylko 1 liczba pasuje 
            //dodaj jako mozliwa, jesli nie mozliwa a to nextXOR to usun z mozliwych
            if (posibleNumbers[i][ii][iii][iiii] && posibleNumbers[i][(ii+1)%(BankNum * AccPerBank)][iii][iiii]) {
              if (!nextXOR) { //only in 1st iterotion
                finalPossible[i][iii][iiii] = true;
                counter ++;
              } // later we only narrow down
            } else {
              finalPossible[i][iii][iiii] = false;
            }
          }
          //if counter = 1 wiemy ze to ta liczba
          if (counter == 1) {
            break; // nie musimy szukac dalej, wiemy co to jest za liczba
          } else {
            nextXOR = true; // we check only numbers possible in prev xors
          }
        }
      }
    }
  }


  //konta x mozliwosci x 8
  short ***As = malloc(BankNum * AccPerBank * sizeof(short**));
  // unsigned short ***results = malloc(BankNum * AccPerBank * sizeof(unsigned short**));
  if (As == NULL) {
    fprintf(stderr, "Memory for As allocation failed\n");
    return EXIT_FAILURE;
  }
  // Allocate memory for each account
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    short posible = BankNum * 1000;
    As[i] = malloc(posible * sizeof(short*));
    if (As[i] == NULL) {
      fprintf(stderr, "Memory for As for each acc allocation failed for acc %d\n", i);
      // Free previously allocated memory before exiting
      for (short j = 0; j < i; ++j) {
        free(As[j]);
      }
      free(As);
      return EXIT_FAILURE;
    }
    // Allocate memory for each row
    for (short ii = 0; ii < posible; ++ii) {
      As[i][ii] = malloc((8) * sizeof(short));
      if (As[i][ii] == NULL) {
        fprintf(stderr, "Memory for As allocation failed for row %d\n", ii);
        // Free previously allocated memory before exiting
        for (short j = 0; j < ii; ++j) {
          free(As[i][j]);
        }
        free(As[i]);
        for (short j = 0; j < i; ++j) {
          for (short jj = 0; jj < posible; ++jj) {
            free(As[j][jj]);
          }
          free(As[j]);
        }
        free(As);
        return EXIT_FAILURE;
      }
    }
  } 
  // last filled As
  short *asCounter = malloc(BankNum * AccPerBank * sizeof(short)); // range 0 - 4999 for all accounts
  if (asCounter == NULL) {
    fprintf(stderr, "Memory for As allocation failed\n");
    return EXIT_FAILURE;
  }
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    asCounter[i] = 0;
  }

  //Co chcemy: dla kazdego konta przypisac mozliwe AAAAA
  //przy czym one sa liczone razem, tj potem przy CC trzeba
  // brac all 8 AAAA
  //opcja 1: zapisac AAAA do nowej tablicy A..
  //opcja 2: zaraz po wyliczeniu potencjalnych A oblicz nr banku?
  /*
  pracujemy na mozliwych liczbach, czyli jak sie okaze z A czy CC
  wyjdzie ze liczba X na pozycji Y jest nie mozliwa to ja usuwamy
  no i robimy tak az na kazdej pozycji mamy 1 liczbe 
  UWAGA: tylko jezeli cos jest na 100% NIEMOZLIWE to usuwamy

  */

  short *rightAccCounter = malloc(BankNum * AccPerBank * sizeof(short)); // range 0 - 4999 for all accounts
  if (rightAccCounter == NULL) {
    fprintf(stderr, "Memory for As allocation failed\n");
    return EXIT_FAILURE;
  }
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    rightAccCounter[i] = 0;
  }

  bool found = false;
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    //check As - for each possible bank ID
    //if id is ok, then check possible numbers and k,
    //if all ok add them to possible A-s
    bool possibleAs[8][10] = {false};
    for (unsigned short ii = 0; ii < bankIds_size; ++ii) {
      short id = bankIds[ii];
      short l1 = (id / 1000) % 10;
      short l2 = (id / 100)  % 10;
      short l3 = (id / 10)   % 10;
      short l4 =  id         % 10;
      /*
      How many possible As we have?
      BankNum * 1000 > |As|
      lets be unOptimal this time
      */
      if (finalPossible[i][2][l1] &&
          finalPossible[i][3][l2] &&
          finalPossible[i][4][l3] &&
          finalPossible[i][5][l4]) {
        for (short iii = 0; iii < 10; ++iii) {
          if (finalPossible[i][6][iii]) {
            for (short iiii = 0; iiii < 10; ++iiii) {
              if (finalPossible[i][7][iiii]) {
                for (short iiiii = 0; iiiii < 10; ++iiiii) {
                  if (finalPossible[i][8][iiiii]) {
                    const unsigned short account[9] = {
                      0,0,l1,l2,l3,l4,iii,iiii,iiiii
                    };
                    short k = calculate_checksum(account);
                    if (finalPossible[i][9][k]) {
                      possibleAs[0][l1]    = true; As[i][asCounter[i]][0] = l1;
                      possibleAs[1][l2]    = true; As[i][asCounter[i]][1] = l2;
                      possibleAs[2][l3]    = true; As[i][asCounter[i]][2] = l3;
                      possibleAs[3][l4]    = true; As[i][asCounter[i]][3] = l4;
                      possibleAs[4][iii]   = true; As[i][asCounter[i]][4] = iii;
                      possibleAs[5][iiii]  = true; As[i][asCounter[i]][5] = iiii;
                      possibleAs[6][iiiii] = true; As[i][asCounter[i]][6] = iiiii;
                      possibleAs[7][k]     = true; As[i][asCounter[i]][7] = k;
                      asCounter[i]++;
                    }
                  }
                } 
              }
            }
          }
        }
      }
    } //we checked all posislbe As, so now narrow down finalPossible
    for (short ii = 0; ii < 8; ++ii) {
      for (short iii = 0; iii < 10; ++iii) {
        finalPossible[i][2+ii][iii] = possibleAs[ii][iii];
      }
    }
    //choose kk, and for each check all possibiliteis
    short tmpAcc[28]; // later
    short possibilites[ACCLEN] = {0};
    for (short ii = 0; ii < ACCLEN; ++ii) {
      for (short iii = 0; iii < 10; ++iii) {
        possibilites[ii] += finalPossible[i][ii][iii];
      }
    }

  
    bool breakFlag = false;
    //CC CHECK
    for (short j = 0; j < 10; ++j) { // find first c
      if (finalPossible[i][0][j]) { 
        for (short jj = 0; jj < 10; ++jj) { // find second c
          if (finalPossible[i][1][jj]) { //both cc are possible
            //here for those CC we check ALL posibilities
            // printf("\nCC = %d%d\n",j,jj);
            short tmpAsCounter = asCounter[i];
            while (tmpAsCounter) { // check all As
              tmpAsCounter--;
              // printf("as %d: ", tmpAsCounter);
              for (short ii = 0; ii < 8; ++ii) {
                tmpAcc[ii] = As[i][tmpAsCounter][ii];
                // printf("%d",As[i][tmpAsCounter][ii]);
              }
              // printf("\n");
              short tmpPos[ACCLEN];
              short tmpPosSum = 0; //posssibly 1
              for (short jjj = 0; jjj < ACCLEN; ++jjj) {
                tmpPos[jjj] = possibilites[jjj] - 1;
                tmpPosSum += possibilites[jjj] - 1;
              }
              //now all possible rest 
              bool narrowDownFlag = false;
              while (tmpPosSum) {

                //TODO: it does it once I more all possibliteis for given As
                // + tmpPos needs to be made true
                //dla 1 liczby ok, ale potem kazda nast ma tylko 1 wybor l pierwszej
                for(short jjj = 0; jjj < 16; ++jjj) {
                  short position = tmpPos[jjj+10];
                  for (short jjjj = 0; jjjj < 10; ++jjjj) {
                    //choose last possible number, tmpPos[jjj] -= 1
                    if (finalPossible[i][jjj+10][jjjj]) { 
                      if (position == 0) {
                        tmpAcc[jjj+8] = jjjj;
                        //obecne podejscie zaklada 2x zliczanie pozycji z pierwsza mozliwa cyfra
                        // + jest to ze tmpPosSum powinna byc rowna 0 po wszystkich kombinacjach
                        if (!narrowDownFlag) { //tylko dla pierwszej zmiany liczby
                          if (tmpPos[jjj+10]) {
                            /*
                              kiedy zmniejszamy ilosc mozliwosc na pozycji jjj
                              to tak naprawde zmieniamy liczbe na pozycji jjj 
                              w koncie wiec poprzednie wartosc jjj trzeba ustawic
                              na possibilites[idx] - 1 tak zeby sprawdzic wszystkie mozl
                              dla tej liczby
                            */
                            
                            tmpPos[jjj+10]--;
                            for (short ii = 10; ii < jjj+10; ++ii) {
                              tmpPos[ii] = possibilites[ii] - 1;
                            }
                            narrowDownFlag = true;
                          }
                        }
                        break;
                      }
                      --position;
                    }
                  }
                }
                narrowDownFlag = false;
                tmpAcc[24] = 2;
                tmpAcc[25] = 5;
                tmpAcc[26] = 2;
                tmpAcc[27] = 1;

                size_t sum = 0;
                for (short ii = 0; ii < ACCLEN + 2; ++ii) {
                  size_t value = tmpAcc[ii];
                  for (short jjj = ii; jjj < ACCLEN + 2; ++jjj) {
                    value *= 10;
                  }
                  sum += value;
                }
                sum %= 97;
                //sum + kk = 1 = 98
                short kk = 98 - sum;

                if (j == (kk - (kk % 10)) / 10 &&
                  jj == kk % 10) {
                  //konto jest git, dodaj je do listy mozliwych czy cos
                  rightAccCounter[i]++;

                  bool t = true;
                  t = t && ((plainAcccounts[i][0]-'0') == j &&
                            (plainAcccounts[i][1]-'0') == jj);
                  for (short iii = 0; iii < ACCLEN-2; ++iii) {
                    t = t && ((plainAcccounts[i][iii+2]-'0') == tmpAcc[iii]);
                  }
                  bool printFlag = false;
                  if (t) {
                    printFlag = true;
                    printf("\n\n\n");
                    printf("RIGHT acc %02d: ",i);
                    printf("%d",(kk - (kk % 10)) / 10);
                    printf("%d",kk % 10);
                    for (short k = 0; k < ACCLEN-2; ++k) {
                      printf("%d",tmpAcc[k]);
                    }
                    printf("\n");
                    printf("tacc      %02d: ", i);
                    printf("%s\n\n\n", plainAcccounts[i]);
                  }

                  short ac[ACCLEN];
                  short ac2[ACCLEN];
                  ac[0] = j; ac[1] = jj;
                  for (short l = 2; l < ACCLEN; ++l) {
                    ac[l] = tmpAcc[l-2];
                  }
                  breakFlag = false;
                  for (short l = 0; l < BankNum * AccPerBank; ++l) { 
                    if (i != l) {
                      for (short ll = 0; ll < ACCLEN; ++ll) {
                        ac2[ll] = ac[ll] ^ results[i][l][ll];
                        // if (ac2[ll] > 9) {
                        //   breakFlag = true;
                        //   break;
                        // } else if (!posibleNumbers[i][ll][ac2[ll]]) {
                        //   breakFlag = true;
                        //   break;
                        // }
                      }
                      if (!calculateCC(ac2,l,finalPossible, printFlag)) {
                        if (printFlag) {
                          for (short o = 0; o < 10; ++o) {
                            printf("fp[%d][0][%d] = %d, ",i,o,finalPossible[i][0][o]);
                            printf("fp[%d][1][%d] = %d\n",i,o,finalPossible[i][1][o]);
                          }
                          printf("i: %d, l: %d\n", i, l);
                          for (short o = 0; o < ACCLEN; ++o) {
                            printf("%d",ac[o]);
                          }
                          printf("\n");
                          printf("%s\n", plainAcccounts[i]);
                          printf("\n");
                          for (short o = 0; o < ACCLEN; ++o) {
                            printf("%d",ac2[o]);
                          }
                          printf("\n");
                          printf("%s\n\n", plainAcccounts[l]);
                        }
                        breakFlag = true;
                        break;
                      }
                    }
                    if (breakFlag) {
                      break;
                    }
                  }
                  if(!breakFlag) { // if in  all ok
                    for (short ll = 0; ll < ACCLEN; ++ll) {
                      for (short lll = 0; lll < 10; ++lll) {
                        finalPossible2[i][ll][lll] = false;
                      }
                    }
                    for (short ll = 0; ll < ACCLEN; ++ll) {
                      finalPossible2[i][ll][ac[ll]] = true;
                    }
                    for (short l = 0; l < BankNum * AccPerBank; ++l) { 
                      if (i != l) {
                        for (short ll = 0; ll < ACCLEN; ++ll) {
                          ac2[ll] = ac[ll] ^ results[i][l][ll];
                          finalPossible2[l][ll][ac2[ll]] = true;
                        }
                      }
                    }
                    printf("i: %d, found: %d\n", i, found);

                    found = true;
                  }
                  // bool t = true;
                  // t = t && ((plainAcccounts[i][0]-'0') == j &&
                  //           (plainAcccounts[i][1]-'0') == jj);
                  // for (short iii = 0; iii < ACCLEN-2; ++iii) {
                  //   t = t && ((plainAcccounts[i][iii+2]-'0') == tmpAcc[iii]);
                  // }
                  // if (t) {
                  //   printf("\n\n\n");
                  //   printf("RIGHT acc %02d: ",i);
                  //   printf("%d",(kk - (kk % 10)) / 10);
                  //   printf("%d",kk % 10);
                  //   for (short k = 0; k < ACCLEN-2; ++k) {
                  //     printf("%d",tmpAcc[k]);
                  //   }
                  //   printf("\n");
                  //   printf("tacc      %02d: ", i);
                  //   printf("%s\n\n\n", plainAcccounts[i]);
                  // }
                }
                tmpPosSum = 0;
                for (short jjj = 10; jjj < ACCLEN; ++jjj) {
                  // tmpPos[jjj] = possibilites[jjj] - 1;
                  tmpPosSum += tmpPos[jjj];
                }
                // printf("tmpPosSum %d\n", tmpPosSum);
                if (found){
                  break;
                }
              }
              // printf("tmpAsCounter %d\n", tmpAsCounter);
              if (found) {
                break;
              }
            }
          }
          if (found){
            break;
          }
        }
      }
      if (found){
        break;
      }
    }
    // if (!breakFlag){
    //   ;
    // }
    

    // short tmpAcc[29];
    //   for (short i = 0; i < ACCLEN - 2; ++i) {
    //     tmpAcc[i] = account[i+2];
    //   }
    //   tmpAcc[24] = 2;
    //   tmpAcc[25] = 5;
    //   tmpAcc[26] = 2;
    //   tmpAcc[27] = 1;

    //   //to poniezej wrzucic do osobnej funkcji mozna
    //   //w bankCrack mozna 2 konta naraz sprawdzac czy CC sie zgadza
    //   //

    //   size_t sum = 0;
    //   for (short i = 0; i < ACCLEN + 1; ++i) {
    //     size_t value = tmpAcc[i];
    //     for (short j = i; j < ACCLEN + 1; ++j) {
    //       value *= 10;
    //     }
    //     sum += value;
    //   }
    //   sum %= 97;
    //   //sum + kk = 1 = 98
    //   short kk = 98 - sum;
    //   account[0] = (kk - (kk % 10)) / 10;
    //   account[1] = kk % 10;
    if (found){
      break;
    }
  }

  // for (short i = 0; i < BankNum * AccPerBank; ++i) {
  //  // 69114068428387524505732721
  //   // posibleNumbers[i];
  //   printf("acc %02d: 0 1 2 3 4 5 6 7 8 9\n", i);
  //   for (short iii = 0; iii < ACCLEN; ++iii) {
  //     printf("num %02d: ", iii);
  //     for (short iiii = 0; iiii < 10; ++iiii) {
  //       //for given acc, 
  //       printf("%d " ,finalPossible[i][iii][iiii]);
  //     }
  //     printf("\n");
  //   }
  //   printf("\n");
  // }
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    printf ("acc  %02d: ",i);
    for (short iii = 0; iii < ACCLEN; ++iii) {
      short sum = 0;
      short id = -1;
      for (short iiii = 0; iiii < 10; ++iiii) {
        // sum += finalPossible[i][iii][iiii];
        // if (finalPossible[i][iii][iiii]) {
        //   id = iiii;
        // }
        sum += finalPossible2[i][iii][iiii];
        if (finalPossible2[i][iii][iiii]) {
          id = iiii;
        }
      }
      if (sum == 1) {
        printf("%d",id);
      } else {
        printf("x");
      }
    }
    printf("\n");
    printf("tacc %02d: ", i);
    printf("%s\n", plainAcccounts[i]);
    printf("\n");
  }

  printf("right acc num:\n");
  for (size_t i = 0; i < BankNum * AccPerBank; i++) {
    printf ("%d, ",rightAccCounter[i]);
  }
  printf("\n");

  // free wszystko
  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < BankNum * AccPerBank; ++ii) {
      for (short iii = 0; iii < ACCLEN; ++iii) {
        free(posibleNumbers[i][ii][iii]);
      }
      free(posibleNumbers[i][ii]);
    }
    free(posibleNumbers[i]);
  }
  free(posibleNumbers);

  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < BankNum * AccPerBank; ++ii) {
      free(results[i][ii]);
    }
    free(results[i]);
  }
  free(results);

  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < BankNum * 1000; ++ii) {
      free(As[i][ii]);
    }
    free(As[i]);
  }
  free(As);

  for (short i = 0; i < BankNum * AccPerBank; ++i) {
    for (short ii = 0; ii < ACCLEN; ++ii) {
      free(finalPossible[i][ii]);
    }
    free(finalPossible[i]);
  }
  free(finalPossible);

  free(rightAccCounter);
  free(asCounter);
  free(accounts);
  free(plainAcccounts);
  return EXIT_SUCCESS;
}

