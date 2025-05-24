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
	*morseTable = malloc(sizeof(MorseCode));
	
	FILE *file = fopen("resources/morse_table.csv", "r");
	
	if (file == NULL) {
		perror("Failed loading file!");
		exit(EXIT_FAILURE);
	}

	char line[16];
	const char *delimiter = "\t";
	while (fgets(line, 16, file)) {
		*morseTable = realloc(*morseTable, (*morseTableSize + 1) * sizeof(MorseCode));

		char *token = strtok(line, delimiter);
		(*morseTable)[*morseTableSize].letter = token[0];

		token = strtok(strtok(NULL, "\n"), delimiter);
		(*morseTable)[*morseTableSize].morse = token;

		(*morseTableSize)++;
	}

	fclose(file);

}