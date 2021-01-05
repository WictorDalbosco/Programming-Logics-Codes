/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char *name;
    char *cidade;
}PESSOA;

char *readLine(FILE *stream) {
    scanf(" ");

	char *string = NULL;
	int pos = 0;
	
    do{
        string = (char *) realloc(string, pos+1);
		string[pos] = (char) fgetc(stream);
		pos++;

	} while (string[pos-1] != '.' && !feof(stream) );

	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	
	return string;

}

void cadastrarPessoas(PESSOA **celebridades,int nPessoas){

	*celebridades = (PESSOA *)calloc(nPessoas,sizeof(PESSOA));
	if(*celebridades == NULL)printf("Nao alocou pessoas");
	for (int i = 0; i < nPessoas; i++){
		(*celebridades)[i].name = readLine(stdin);
		(*celebridades)[i].cidade = readLine(stdin);
	}
}

void imprimirListaPessoas(PESSOA *pessoas, int nPessoas){
	for (int i = 0; i < nPessoas; i++){
		printf("%s.\n",pessoas[i].name);
	}	
}

void desalocarListaPessoas(PESSOA *pessoas,int nPessoas){
	for (int i = 0; i < nPessoas; i++){
		free(pessoas[i].name);
		free(pessoas[i].cidade);
	}
	free(pessoas);	
}

/*void trocaStrings(char **str1, char **str2){
	char *aux =(char *)calloc((strlen(*str1)+1),sizeof(char));
	strcpy(aux,*str1);
	*str1 = (char *)realloc(*str1,(strlen(*str2)+1) * sizeof(char));
	strcpy(*str1,*str2);
	*str2 = (char *)realloc(*str2,(strlen(aux)+1) * sizeof(char));
	strcpy(*str2,aux);
	free(aux);
}

void trocaPosicao(PESSOA **p1, PESSOA **p2){
	PESSOA *aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}*/

void trocaStrings(char **str1, char **str2){
	char *aux = *str1;
	*str1 = *str2;
	*str2 = aux;
}

void cocktailAlfabetico(PESSOA **pessoas, int nPessoas){
	bool houveTroca = true;
	int inicio = 0;
	int fim = nPessoas -1;

	while (houveTroca == true){
		houveTroca = false;
		for (int i = inicio; i < fim; i++){
			if(strcasecmp((*pessoas)[i].name,(*pessoas)[i+1].name) > 0){
				trocaStrings(&(*pessoas)[i].name,&(*pessoas)[i+1].name);
				trocaStrings(&(*pessoas)[i].cidade,&(*pessoas)[i+1].cidade);
				houveTroca = true;
			}
		}
		if(!houveTroca) break;

		houveTroca = false;
		--fim;

		for (int i = fim-1; i >= inicio; --i){
			if(strcasecmp((*pessoas)[i].name,(*pessoas)[i+1].name) > 0){
				trocaStrings(&(*pessoas)[i].name,&(*pessoas)[i+1].name);
				trocaStrings(&(*pessoas)[i].cidade,&(*pessoas)[i+1].cidade);
				houveTroca = true;
			}	
		}
		++inicio;
	}
}

int buscaBinariaRecursiva(PESSOA *pessoa,int inicio, int fim, char *nomeChave){
	if (fim >= inicio){
		int meio = inicio + (fim - inicio)/2;

		if (strcasecmp(pessoa[meio].name,nomeChave) == 0){
			return meio;
		}
		if (strcasecmp(pessoa[meio].name,nomeChave) > 0){
			return buscaBinariaRecursiva(pessoa,inicio,meio-1,nomeChave);
		}
		return buscaBinariaRecursiva(pessoa,meio+1,fim,nomeChave);
	}
	return -1;
}

void buscarCelebridade(int nBuscas,PESSOA *pessoas, int nPessoas){
	char *nomeBusca = NULL;
	int posicao = 0;
	for (int i = 0; i < nBuscas; i++){
		nomeBusca = readLine(stdin);
		posicao = buscaBinariaRecursiva(pessoas,0,nPessoas,nomeBusca);
		if(strcmp(pessoas[posicao].cidade,"Sao Carlos") == 0){
			printf("1\n"); //São carlos
		}else{
			printf("0\n"); //Não é de sanca
		}
		
		free(nomeBusca);
	}	
}

int main(int argc, char *argv[]){

    int nPessoas = 0,nBuscas = 0;
	PESSOA *celebridades = NULL;
	scanf("%d",&nPessoas);

	cadastrarPessoas(&celebridades,nPessoas);

	cocktailAlfabetico(&celebridades,nPessoas);

	imprimirListaPessoas(celebridades,nPessoas);

	scanf("%d",&nBuscas);

	buscarCelebridade(nBuscas,celebridades,nPessoas);

	desalocarListaPessoas(celebridades,nPessoas);

    return 0;
}