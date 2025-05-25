#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>

#include "read.h"
#include "consts.h"
#include "encode.h"
#include "decode.h"
#include "flags.h"

int main(int argc, char *argv[]) {
	int option_index = 0;
	int encode_flag = false;
	int decode_flag = false;
	char wordspacer[4] = "   ";
	char *input_filename = NULL;
	char *output_filename = NULL;

	static struct option long_options[] = {
		{"help", no_argument, false, 'h'},
		{"programmer-info", no_argument, false, 0},
		{"encode", no_argument, false, 'e'},
		{"decode", no_argument, false, 'd'},
		{"slash-wordspacer", no_argument, false, 0},
		{"output", required_argument, false, 'o'},
		{0, 0, 0, 0}
	};

	int opt;
	while ((opt = getopt_long(argc, argv, "hedo:", long_options, &option_index)) != -1) {
		switch (opt) {
			case 'h':
				printf("%s", help_text);
				return EXIT_SUCCESS;
			case 'e':
				encode_flag = true;
				break;
			case 'd':
				decode_flag = true;
				break;
			case 'o':
				output_filename = optarg;
				break;
			case 0:
				if (strcmp("slash-wordspacer", long_options[option_index].name) == 0) {
					strcpy(wordspacer, " / ");
					break;
				}
				else if (strcmp("programmer-info", long_options[option_index].name) == 0) {
					// print info
					return EXIT_SUCCESS;
				}
			default:
				fprintf(stderr, "Usage: %s [-e|--encode] [-d|--decode] [inputfile] [-o|--output file]\n", argv[0]);
				return 1;
		}
	}

	if (encode_flag && decode_flag) {
		fprintf(stderr, "Error: Cannot specify both --encode and --decode.\n");
		return 1;
	}
	
	int mode = decode_flag ? true : false; // Default to encode (0) if nothing set

	// Check for input file (positional argument after flags)
	if (optind < argc) {
		input_filename = argv[optind];
	}

	FILE *in = input_filename ? fopen(input_filename, "r") : stdin;
	if (!in) {
		perror("Error opening input file");
		return 1;
	}

	FILE *out = output_filename ? fopen(output_filename, "w") : stdout;
	if (!out) {
		perror("Error opening output file");
		if (in != stdin) fclose(in);
		return 1;
	}

	MorseCode *morseTable = NULL;
	size_t morseTableSize = 0;
	readCSV(&morseTable, &morseTableSize);
	
	char buffer[1024];
	char *output = malloc(1024);
	while (fgets(buffer, sizeof(buffer), in)) {
		buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
		if (mode == 0) {
			encode(buffer, output, morseTable, morseTableSize, wordspacer);
			if (out == stdout) printf("%s\n", output);
			else {
				fprintf(out, "%s ", output);
				fprintf(out, "\n");
			}
		} else {
			decode(buffer, output, morseTable, morseTableSize);
			if (out == stdout) printf("%s\n", output);
			else {
				fprintf(out, "%s ", output);
				fprintf(out, "\n");
			}
		}
	}
	

	if (in != stdin) fclose(in);
	if (out != stdout) fclose(out);

	free(morseTable);
	free(output);

	return EXIT_SUCCESS;

}