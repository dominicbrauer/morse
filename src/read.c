#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"
#include "consts.h"

/**
 * Parses MorseCode from CSV.
 * @param morseTable empty table
 * @param morseTableSize starter size of morseTable
 */
void readCSV(MorseCode **morseTable, size_t *morseTableSize) {
	FILE *file = fopen("resources/morse_table.csv", "r");
	
	if (file == NULL) {
		perror("Failed loading file!");
		exit(EXIT_FAILURE);
	}

	char line[16];
	while (fgets(line, 16, file)) {
		*morseTable = realloc(*morseTable, (*morseTableSize + 1) * sizeof(MorseCode));

		char *token = strtok(line, "\t");
		(*morseTable)[*morseTableSize].letter = token[0];

		token = strtok(NULL, "\n");
		(*morseTable)[*morseTableSize].morse = strdup(token);

		(*morseTableSize)++;
	}

	fclose(file);

}