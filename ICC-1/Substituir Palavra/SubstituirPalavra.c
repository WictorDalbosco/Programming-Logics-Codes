/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNÇÃO READLINE
char *readline(FILE *stream) {
	char *string = NULL;

    //Posição do ponteiro do stream
	int pos = 0;
	
    do {
		//Alocamos um byte
        string = (char *) realloc(string, pos+1);

        //Lemos um caractere do stream e colocamos na string em sua respectiva 
        //posição
		string[pos] = (char) fgetc(stream);

        //Próximo caractere
		pos++;

	} while (string[pos-1] != '\n' && !feof(stream));


	//Checar se não há nenhuma quebra de linha 
	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

    //Limpamos o \n que vier incluido no stream
	string[pos-1] = '\0';

    //Realocamos para o novo tamanho da string
	string = (char *) realloc(string, pos);
	
	return string;

    free(string);
}

//FUNÇÃO PARA SUBSTITUIR PALAVRA
char *substituiPalavra(const char *p1, const char *p2, const char *fraseVelha){

    char *frase;
    int i, count = 0;
    int tamP1 = strlen(p1);
    int tamP2 = strlen(p2);

    //Conferindo quantas vezes a palavra a ser substituida ocorre
    //Na frase digitada
    for(i = 0; fraseVelha[i] != '\0'; i++){
        //Atraves da funcao strstr podemos saber se p1 ocorre na frase
        if(strstr(&fraseVelha[i], p1) == &fraseVelha[i]){
            count++;
            //Como ja achamos a palavra podemos pular toda ela e continuar a busca
            i = i + (tamP1 - 1);
        }
    }

    //agora realocamos a memória para o tamanho da nova frase
    frase = (char *)malloc(i + count * (tamP2 - tamP1) + 1); 

    i = 0;

    //Agora vamos substituir na frase
    while(*fraseVelha){
        //Se a palavra está na frase 
        if(strstr(fraseVelha, p1) == fraseVelha){
            //Copiamos a palavra nova para a frase
            strcpy(&frase[i], p2);
            //Pulamos então a ocorrência
            i = i + tamP2;
            //Adicionamos o tamanho da palvra na frase
            fraseVelha = fraseVelha + tamP1; 
        }
        else{
            //Se não tem, mantem como está
            frase[i++] = *fraseVelha++;
        }
    }

    //Colocamos o terminador de string
    frase[i] = '\0';
    
    return frase;
    
}

int main(int argc, char *argv[]) {

    //ponteiro da palavra digitada a ser substituida
    char *p1;
    //ponteiro da palavra na frase
    char *p2;
    //ponteiro para a frase digitada
    char *frase;
    //ponteiro para a frase nova
     char *fraseNova;

    //Lemos p1
    p1 = readline(stdin);
    //Limpamos o buffer do stdin para garantir q nada venha junto
    fflush(stdin);

    //Lemos p2
    p2 = readline(stdin);
    fflush(stdin);

    //Lemos a frase
    frase = readline(stdin);
    fflush(stdin);

    //Usamos a funçao para substituir a palavra
    fraseNova = substituiPalavra(p1,p2,frase);

    //Imprimimos a nova frase
    printf("%s \n",fraseNova);

    //Liberamos todos os espaços alocados
    free(p1);
    free(p2);
    free(frase);
    free(fraseNova);

    return 0;
}