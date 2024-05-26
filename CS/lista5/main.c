#include "head1.h"
#include<ctype.h>

int main(int argc, char* argv[argc+1]) {
  if (argc < 4) {
    printUsage();
    return EXIT_FAILURE;
  } 
  if (!atoi(argv[1])) {
    printf("First argument (mode) should be a digit. \n\
    See below which mode you want to choose:\n");
    printUsage();
    return EXIT_FAILURE;
  }
  short mode = atoi(argv[1]);
  if (mode == 1) {
    if (keyCompare(\
      (unsigned char*) argv[2],\
      (unsigned char*) argv[3],\
      (unsigned char*) argv[4])) {
      return EXIT_FAILURE;
    } else {
      return EXIT_SUCCESS;
    }
  } else if (mode == 2) {
    if (argc < 5) {
      printUsage();
      return EXIT_FAILURE;
    } 
    if (keyDetect(\
      (unsigned char*) argv[2],\
      (unsigned char*) argv[3],\
      (unsigned char*) argv[4],\
      (unsigned char*) argv[5])) {
      return EXIT_FAILURE;
    } else {
      return EXIT_SUCCESS;
    }
  } else if (mode == 3) {
    if (bankCrack(\
      (unsigned char*) argv[2],\
      strtol(argv[3], NULL, 10),\
      strtol(argv[4], NULL, 10))) {
      return EXIT_FAILURE;
    } else {
      return EXIT_SUCCESS;
    }
  } else {
    printUsage();
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
