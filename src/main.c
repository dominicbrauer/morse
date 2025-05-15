#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"
#include "read.h"

int main(int argc, char *argv[]) {

  if (argc > 1) {
    printf("%s\n", argv[1]);
  }

  char *text = "hallo Welt $ mein @ Name +4 ist bubi9";

  printf("%s\n", text);

  char **codes;
  size_t codes_size;
  readCSV(&codes, &codes_size);

  encode(&text, codes, codes_size);

  free(codes);

  printf("#%s#\n", text);

  free(text);

  return EXIT_SUCCESS;

}