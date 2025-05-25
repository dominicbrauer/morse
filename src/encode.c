#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "encode.h"
#include "consts.h"

/**
 * Encodes text -> morse.
 * Note that text will be overwriten by
 * the the morse sequence.
 * @param given text in ASCII
 * @return text in morse
 */
void encode(char **text, char **codes, size_t codes_size) {
	char *encoded = malloc(sizeof(char));
	encoded[0] = '\0';

	for (int i = 0; (*text)[i] != '\0'; i++) {
		// Handle space char in text
		if ((*text)[i] == SPACE) {
			encoded = realloc(encoded, (strlen(encoded) + 1 + 4) * sizeof(char));
			strcat(encoded, TRIPLE_SPACE_NT);
			continue;
		}

		// Handle letters
		for (int j = 0; j < codes_size; j++) {
			if (toupper((unsigned char)(*text)[i]) == codes[j][0]) {
				encoded = realloc(encoded, (strlen(encoded) + 1 + strlen(codes[j+1])) * sizeof(char));
				strcat(encoded, codes[j+1]);
				break;
			}
			// Unknown character
			if (j == codes_size - 1) {
				encoded = realloc(encoded, (strlen(encoded) + 1 + 2) * sizeof(char));
				strcat(encoded, (char[]){UNKNOWN_CHAR, '\0'});
			}
		}

		// Handle if space is needed in morse
		if ((*text)[i+1] != '\0' && (*text)[i+1] != SPACE) {
			encoded = realloc(encoded, (strlen(encoded) + 1 + 2) * sizeof(char));
			strcat(encoded, (char[]){SPACE, '\0'});
		}
	}

	*text = NULL;
	*text = malloc((strlen(encoded) + 1) * sizeof(char));
	strcpy(*text, encoded);

	free(encoded);

	return;

}