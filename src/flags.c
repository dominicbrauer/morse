#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flags.h"

const char help_text[] =
	"Usage: ./morse [OPTIONS]\n"
	"Options:\n"
	"  -h, --help	Shows this message.\n"
	"  --programmer-info	Prints the author information.\n"
	"  -e, --encode	Encodes the given text.\n"
	"  -d, --decode	Decodes the given text.\n"
	"  -o, --output	Redirects the stream to a file.\n"
	"  --slash-wordspacer	Uses 'SP/SP' instead of 'SPSPSP' between words.\n"
;