#include <stdio.h>
#include <stdlib.h>

#include "ai.c"
#include "colourful.c"

/* Repeatable project description:
   Let humans play games against AIs. */

size_t get_input(char** user_input) {
	size_t bytes_read;	
	size_t nbytes = 100;

	print_colour("HUMAN", FG_YELLOW, BOLD);
	printf(": ");
	fflush(stdout);
	bytes_read = getline(user_input, &nbytes, stdin);

	if (bytes_read == -1) {
		return IE_EOF;
	} else {
		return bytes_read;
	}
}

void repeatable_loop() {
	char* user_input = NULL;
	char* ai_response;

	for (;;) {
		size_t result = get_input(&user_input);
		if (result == IE_EOF) {
			printf("\n");
			print_colour("Thank you for using repeatable.\n",
				FG_CYAN, NON_BOLD);
			exit(0);
		} else if (result == IE_NO_INPUT) {
			print_colour("Please type at least one character.\n",
				FG_CYAN, NON_BOLD);
		} else {
			ai_response = respond(user_input);
			print_colour("AI", FG_MAGENTA, BOLD);
			printf(": ");
			printf("%s\n", ai_response);
		}
		free(user_input);
		user_input = NULL;
	}
}

int main() {
	print_colour("Welcome to REPEATABLE.\n", FG_CYAN, NON_BOLD);
	repeatable_loop();
}
