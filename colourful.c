#include "colours.h"

/* Makes things a bit more colourful. */

void print_colour(char* str, int color, int bold) {
	printf("%c[%d;%dm", 0x1B, bold, color);
	fputs(str, stdout);
	printf("%c[%dm", 0x1B, 0);
	fflush(stdout);
}
