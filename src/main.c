#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flags.h"
#include "encode.h"

int main(int argc, char *argv[]) {

  if (argc > 1) {
    printf("%s\n", argv[1]);
  }

  char text[] = "hallo Welt $ mein Name +4 ist bubi9";

  encode(text);

  // printf("%s\n", text);

  return EXIT_SUCCESS;

}