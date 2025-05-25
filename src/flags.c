#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flags.h"

const char * const help_text =
	"Usage: ./morse [OPTIONS]\n"
	"Options:\n"
	"  -h, --help	Shows this message.\n"
	"  --programmer-info	Prints the author information.\n"
	"  -e, --encode	Encodes the given text.\n"
	"  -d, --decode	Decodes the given text.\n"
	"  -o, --output	Redirects the stream to a file.\n"
	"  --slash-wordspacer	Uses 'SP/SP' instead of 'SPSPSP' between words.\n"
;

const char * const INFO_JSON = {
	"{\n"
	"    \"firstname\": \"Dominic\",\n"
	"    \"surname\": \"Brauer\",\n"
	"    \"branch_of_study\": \"TIM\",\n"
	"    \"contact\": \"dominicbrauer06@gmail.com\"\n"
	"}\n"
};
