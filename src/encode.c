#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "read.h"

const char SPACE = ' ';
const char UNKNOWN_CHAR = '*';

/**
 * Encodes text -> morse.
 * Note that text will be overwriten by
 * the the morse sequence.
 * @return given text in ASCII
 */
void encode(char text[]) {
  size_t codes_size;
  char *codes[256];
  readCSV(codes, &codes_size);

  char encoded[1024] = {'\0'};

  for (int i = 0; text[i] != '\0'; i++) {
    // Handle space char in text
    if (text[i] == SPACE) {
      strcat(encoded, (char[]){SPACE, SPACE, SPACE, '\0'});
      continue;
    }
    // Handle letters
    for (int j = 0; j < codes_size; j++) {
      if (toupper((unsigned char)text[i]) == codes[j][0]) {
        strcat(encoded, codes[j+1]);
        break;
      }
      // Unknown character
      if (j == codes_size - 1) {
        strcat(encoded, (char[]){UNKNOWN_CHAR, '\0'});
      }
    }
    // Handle if space is needed in morse
    if (text[i+1] != '\0' && text[i+1] != SPACE) {
      strcat(encoded, (char[]){SPACE, '\0'});
    }
  }

  // strcpy(text, encoded);

  printf("#%s#\n", encoded);

  return;
}