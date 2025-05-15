#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

/**
 * Reads the CSV morse code table into an array.
 * @param codes array where the codes are parsed into
 * @param size counts the eventual entries in codes
 */
void readCSV(char ***codes, size_t *codes_size) {
  size_t code_count = 0;

  *codes = malloc(sizeof(char *));
  (*codes)[0] = malloc(16 * sizeof(char));
  
  const char *delimiter = "\t";
  
  FILE *file = fopen("resources/morse_table.csv", "r");
  
  if (file == NULL) {
    perror("Failed loading file!");
    exit(EXIT_FAILURE);
  }

  char line[16];
  while (fgets(line, 16, file)) {
    // Remove the newline character at the end of the line if it's there
    char *token = strtok(line, delimiter);
    
    while (token != NULL) {
      (*codes)[code_count] = strdup(token);
      code_count++;

      *codes = realloc(*codes, (code_count + 1) * sizeof(char *));
      (*codes)[code_count] = malloc(16 * sizeof(char));
      
      token = strtok(strtok(NULL, "\n"), delimiter);  // Pass NULL to continue tokenizing
    }
  }
  
  if (codes_size) *codes_size = code_count;

  fclose(file);

}