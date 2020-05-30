#include <stdlib.h>
#include <stdio.h>

//
// FILE
//
// stdin = standard input = teclado
//

#define READLINE_BUFFER 4096

char *readline(FILE *stream) {
	char *string = 0;	// Stack (8 bytes)
	int pos = 0;		// Stack (4 bytes)

	do {
		//    0 % 4096, q=0, r=0	---> 1 * READLINE_BUFFER
		//    1 % 4096, q=0, r=1
		//    ...
		// 4095 % 4096, q=0, r=4095
		// 4096 % 4096, q=1, r=0	---> 2 * READLINE_BUFFER
		// 4097 % 4096, q=1, r=1
		// 4098 % 4096, q=1, r=2
		// ...
		// 8192 % 4096, q=2, r=0	---> 3 * READLINE_BUFFER
		// ...
		if (pos % READLINE_BUFFER == 0) {
			int q = pos / READLINE_BUFFER + 1;
			string = (char *) realloc(string, q * READLINE_BUFFER);
		}
		string[pos] = (char) fgetc(stream);
	} while (string[pos++] != '\n');
	string[pos-1] = '\0';

	return string;
}

int main(int argc, char *argv[]) {
	char *string;	// Stack 8 bytes

	string = readline(stdin);
	printf("%s\n", string);
	free(string);

	return 0;
}



