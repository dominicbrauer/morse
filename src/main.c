#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "consts.h"
#include "encode.h"
#include "decode.h"

int main(int argc, char *argv[]) {

	if (argc > 1) {
		printf("%s\n", argv[1]);
	}

	// char *text = "hallo Welt $ mein @ Name +4 ist bubi9";
	char *text = ".... .- .-.. .-.. ---   .-- . .-.. -   *";

	MorseCode *morseTable = NULL;
	size_t morseTableSize = 0;
	readCSV(&morseTable, &morseTableSize);

	// char **codes;
	// size_t codes_size;
	// readCSV(&codes, &codes_size);

	// encode(&text, codes, codes_size);
	// decode(&text, codes, codes_size);

	// free(codes);

	// printf("#%s#\n", text);

	// free(text);

	return EXIT_SUCCESS;

}