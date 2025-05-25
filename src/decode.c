#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "decode.h"
#include "consts.h"

/**
 * Converts a morse code to the
 * corresponding character.
 * @param code the morse code
 * @param morseTable the table containing the translations
 * @param morseTableSize the size of morseTable
 * @return the decoded character
 */
char morseToChar(const char *code, const MorseCode *morseTable, const size_t morseTableSize) {
	for (int i = 0; i < morseTableSize; i++) {
		if (strcmp(code, morseTable[i].morse) == 0) {
			return morseTable[i].letter;
		}
	}
	return UNKNOWN_CHAR; // unknown character
}

/**
 * Decodes a morse sequence into plain text.
 * @param input the morse sequence to be decoded
 * @param output the string pointer where the result is written to
 * @param morseTable the table containing the translations
 * @param morseTableSize the size of morseTable
 */
void decode(const char *input, char *output, const MorseCode morseTable[], const size_t morseTableSize) {
	char buffer[10]; // temporary memory for morse code
	int outIndex = 0, bufIndex = 0;
	int spaceCount = 0;

	for (int i = 0; ; i++) {
		char c = input[i];

		if (c == '.' || c == '-') {
			buffer[bufIndex++] = c;
			spaceCount = 0;
		} else if (c == SPACE || c == '\0') {
			if (bufIndex > 0) {
				buffer[bufIndex] = '\0';
				output[outIndex++] = morseToChar(buffer, morseTable, morseTableSize);
				bufIndex = 0;
			}

			spaceCount++;

			if (spaceCount == 3) { // new word
				output[outIndex++] = SPACE;
				while (input[i + 1] == SPACE) i++;
				spaceCount = 0;
			}

			if (c == '\0') break;
		}
	}

	output[outIndex] = '\0';
}