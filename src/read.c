#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

/**
 * Reads the CSV morse code table into an array.
 * @param codes array where the codes are parsed into
 * @param size counts the eventual entries in codes
 */
void readCSV(char **codes, size_t *size) {
  char lines[128][16];
  int line_count = 0;
  int code_count = 0;
  const char *delimiter = "\t";

  FILE *file = fopen("resources/morse_table.csv", "r");

  if (file == NULL) {
    perror("Failed loading file!");
    exit(EXIT_FAILURE);
  }
  
  while (fgets(lines[line_count], 16, file)) {
    // Remove the newline character at the end of the line if it's there
    size_t len = strlen(lines[line_count]);
    if (len > 0 && lines[line_count][len - 1] == '\n') {
      lines[line_count][len - 1] = '\0';
    }
    
    char *token = strtok(lines[line_count], delimiter);

    while (token != NULL) {
      codes[code_count] = token;
      code_count++;

      token = strtok(NULL, delimiter);  // Pass NULL to continue tokenizing
    }

    line_count++;
    if (line_count >= 128) break;
  }

  if (size) *size = code_count;

  fclose(file);

}