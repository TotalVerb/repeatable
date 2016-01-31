/* A simple "learning" response AI. */

const int INITIAL_SIZE;

struct ResponseMap {
	char** queries, responses;
	int capacity;
	int size;
};

ResponseMap default_respmap() {
	char** q = (char**) calloc(INITIAL_SIZE, sizeof(char*));
	char** r = (char**) calloc(INITIAL_SIZE, sizeof(char*));
	return ResponseMap(q, r, INITIAL_SIZE, 0);
}

void add_to_respmap(respmap

char* respond(char* last_line) {
	return "Hello World!";
}
