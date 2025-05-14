#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "read.h"

/**
 * Encodes text -> morse.
 * @return given text in morse code
 */
void encode(char *text) {
  size_t size;
  char *codes[256];
  readCSV(codes, &size);

  size_t testSize = 0;
  for (int i = 0; codes[i] != NULL; i++) {
    testSize++;
  }
  
  // Capitalize all letters
  for (int i = 0; text[i] != '\0'; i++) {
    text[i] = toupper((unsigned char)text[i]);
  }

  for (int i = 0; i < size; i++) {
    printf("%s\n", codes[i]);
  }
  
}