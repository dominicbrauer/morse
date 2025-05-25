#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "decode.h"
#include "consts.h"

/**
 * 
 */
void decode(char **morse, char **codes, size_t codes_size) {
	char *decoded = malloc(sizeof(char));
	decoded[0] = '\0';

	char **morse_words = malloc(sizeof(char *));
	size_t morse_word_count = 0;

	// this not work
	char *token = strtok(*morse, TRIPLE_SPACE);

	while (token != NULL) {
		morse_words[morse_word_count] = malloc((strlen(token) + 1) * sizeof(char));
		morse_words[morse_word_count] = strdup(token);
		morse_word_count++;

		morse_words = realloc(morse_words, (morse_word_count + 1) * sizeof(char *));

		token = strtok(NULL, TRIPLE_SPACE);  // Pass NULL to continue tokenizing
	}

	for (int i = 0; i < morse_word_count; i++) {
		printf("%s\n", morse_words[i]);
	}

	return;

}