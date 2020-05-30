#include <stdlib.h>
#include <stdio.h>

char *readline(FILE *stream) {
	char *string = NULL;
	int pos = 0;
	do {
		/*if (pos % READLINE_BUFFER == 0) {
			string = (char *) realloc(string, 
					(pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
		}*/
		string = (char *) realloc(string, pos+1);
		//printf("como esta a frase: %s  \n ",string);
		string[pos] = (char) fgetc(stream);

		pos++;

	} while (string[pos-1] != '\n' && !feof(stream));


	//Checar se não há nenhuma quebra de linha 
	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';

	string = (char *) realloc(string, pos);
	printf("Funcao \n");
	
	return string;
}

int main(int argc, char *argv[]) {
	
	char *frase;

	frase = readline(stdin);
	printf("Essa é a string:%s\n", frase);
	free(frase);
	
	//fclose(stdin); // fechar o arquivo que foi aberto

	return 0;
}
