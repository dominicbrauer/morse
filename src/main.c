#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"
#include "read.h"

int main(int argc, char *argv[]) {

  if (argc > 1) {
    printf("%s\n", argv[1]);
  }

  char text[] = "hallo Welt $ mein Name +4 ist bubi9";

  char **codes;
  size_t codes_size;
  readCSV(&codes, &codes_size);

  encode(text, codes, codes_size);

  return EXIT_SUCCESS;

}