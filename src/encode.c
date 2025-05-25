#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "encode.h"
#include "consts.h"

/**
 * Encodes plain text into a morse sequence.
 * @param input the text to be encoded
 * @param output the string pointer where the result is written to
 * @param morseTable the table containing the translations
 * @param morseTableSize the size of morseTable
 */
void encode(const char *input, char *output, const MorseCode morseTable[], const size_t morseTableSize, char wordspacer[]) {
	output[0] = '\0'; // Clear the output buffer

	int i = 0;
	while (input[i] != '\0') {
		char c = input[i];

		// Handle spaces between words
		if (c == SPACE) {
			// Check if previous character wasn't also a space
			// to avoid inserting multiple word gaps
			if (i == 0 || input[i - 1] != SPACE) {
				strcat(output, wordspacer);  // 3 spaces between words
			}
			i++;
			continue;
		}

		// Convert to uppercase
		if (c >= 'a' && c <= 'z') {
			c -= 32;
		}

		int found = 0;
		for (size_t j = 0; j < morseTableSize; j++) {
			if (morseTable[j].letter == c) {
				strcat(output, morseTable[j].morse);
				found = 1;
				break;
			}
		}

		if (!found) {
			strcat(output, (char[]){ UNKNOWN_CHAR, '\0' });
		}

		// Look ahead: if next character is a letter (not space or end), add 1 space
		if (input[i + 1] != '\0' && input[i + 1] != SPACE) {
			strcat(output, " ");
		}

		i++;
	}
}