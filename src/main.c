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

	for (int i = 0; i < morseTableSize; i++) {
		printf("> %c\n", morseTable[i].letter);
		printf("> %s\n", morseTable[i].morse);
	}

	free(morseTable);

	return EXIT_SUCCESS;

}