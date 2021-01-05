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
    float preco;
}LIVRO;

char *readLine(FILE *stream) { //Readline modificada para ler vírgula
    scanf(" ");

	char *string = NULL;
	int pos = 0;
	
    do{
        string = (char *) realloc(string, pos+1);
		string[pos] = (char) fgetc(stream);
		pos++;

	} while (string[pos-1] != ',' && !feof(stream) );

	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	
	return string;

}

void cadastrarLivros(LIVRO **livros,int nLivros){

	*livros = (LIVRO *)calloc(nLivros,sizeof(LIVRO));
	if(*livros == NULL)printf("Nao alocou livros");
	for (int i = 0; i < nLivros; i++){
		(*livros)[i].name = readLine(stdin);
		scanf("%f",&(*livros)[i].preco);
	}
}

void imprimirListaLivros(LIVRO *livros, int nLivros){
	for (int i = 0; i < nLivros; i++){
		printf("%s, R$%0.2f\n",livros[i].name,livros[i].preco);
	}	
}

void desalocarListaLivros(LIVRO *livros,int nLivros){
	for (int i = 0; i < nLivros; i++){
		free(livros[i].name);
	}
	free(livros);	
}

void imprimirPrecosLivros(LIVRO *livro, int nLivros){
	for (int i = 0; i < nLivros; i++){
		printf("%0.2f ",livro[i].preco);
	}
	printf("\n");
}

void merge(LIVRO **livro,LIVRO *esquerdaVetor,LIVRO *meioVetor, LIVRO *direitaVetor,int nLivros,int tamEsquerda,int tamMeio,int tamDireita){
	int total = 0, esquerda = 0, meio = 0, direita = 0;
	LIVRO *temp = (LIVRO *)calloc(nLivros,sizeof(LIVRO));

	//Comparações 3 a 3
	while((esquerda < tamEsquerda) && (meio < tamMeio) && (direita < tamDireita)){
		if (esquerdaVetor[esquerda].preco < meioVetor[meio].preco && esquerdaVetor[esquerda].preco < direitaVetor[direita].preco){
			temp[total++] = esquerdaVetor[esquerda++];
		}else if(meioVetor[meio].preco < esquerdaVetor[esquerda].preco && meioVetor[meio].preco < direitaVetor[direita].preco){
			temp[total++] = meioVetor[meio++];
		}else{
			temp[total++] = direitaVetor[direita++];
		}
	}

	//Comparações 2 a 2
	while((esquerda < tamEsquerda) && (meio < tamMeio)){
		if (esquerdaVetor[esquerda].preco < meioVetor[meio].preco){
			temp[total++] = esquerdaVetor[esquerda++];
		}else{
			temp[total++] = meioVetor[meio++];
		}
	}

	while((esquerda < tamEsquerda) && (direita < tamDireita)){
		if (esquerdaVetor[esquerda].preco < direitaVetor[direita].preco){
			temp[total++] = esquerdaVetor[esquerda++];
		}else{
			temp[total++] = direitaVetor[direita++];
		}
	}

	while((meio < tamMeio) && (direita < tamDireita)){
		if (meioVetor[meio].preco < direitaVetor[direita].preco){
			temp[total++] = meioVetor[meio++];
		}else{
			temp[total++] = direitaVetor[direita++];
		}
	}

	//Comparaçoes unitárias
	while(esquerda < tamEsquerda){
		temp[total++] = esquerdaVetor[esquerda++];
	}

	while(meio < tamMeio){
		temp[total++] = meioVetor[meio++];	
	}

	while(direita < tamDireita){
		temp[total++] = direitaVetor[direita++];
	}
	
	*livro = temp;
}

LIVRO *merge3Vias(LIVRO **livro,int nLivros){
	//Vamos dividir o vetor de acordo com o requisitado
	int tamEsquerda = 0,tamMeio = 0,tamDireita = 0;
	//Criaremos vetores para armazenar os subvetores originários da divisão
	LIVRO *esquerda = NULL, *meio = NULL, *direita = NULL;

	//Caso base
	if (nLivros == 1){
		return *livro;
	}else if(nLivros == 2){
		LIVRO aux1[1];
		aux1[0]=(*livro)[0];

		LIVRO aux2[1];
		aux2[0]=(*livro)[1];

		LIVRO *meio = NULL;

		printf("%0.2f\n",aux1[0].preco);
		printf("%0.2f\n",aux2[0].preco);

		merge(&(*livro),aux1,meio,aux2,nLivros,1,0,1);

		return *livro;
	}

	if(nLivros % 3 == 0){ //Iremos dividir igualmente
		tamEsquerda = nLivros/3;
		tamMeio = nLivros/3;
		tamDireita = nLivros/3;
	}else if(nLivros % 3 == 1){ //A esquerda fica com mais
		tamEsquerda = (nLivros/3)+1;
		tamMeio = nLivros/3;
		tamDireita = nLivros/3;
	}else if(nLivros % 3 == 2){ //As duas primeiras partes do vetor recebem mais
		tamEsquerda = (nLivros/3)+1;
		tamMeio = (nLivros/3)+1;
		tamDireita = nLivros/3;
	}

	//Agora preencheremos os subvetores

	esquerda = (LIVRO *)calloc(tamEsquerda,sizeof(LIVRO));
	for (int i = 0; i < tamEsquerda; i++){
		esquerda[i] = (*livro)[i];
		printf("%0.2f ",esquerda[i].preco);
	}
	printf("\n");
	merge3Vias(&esquerda,tamEsquerda);

	meio = (LIVRO *)calloc(tamMeio,sizeof(LIVRO));
	for (int i = 0; i < tamMeio; i++){
		meio[i] = (*livro)[i+tamEsquerda];
		printf("%0.2f ",meio[i].preco);
	}
	printf("\n");
	merge3Vias(&meio,tamMeio);

	direita = (LIVRO *)calloc(tamDireita,sizeof(LIVRO));
	for (int i = 0; i < tamDireita; i++){
		direita[i] = (*livro)[i+(tamMeio+tamEsquerda)];
		printf("%0.2f ",direita[i].preco);
	}
	printf("\n");
	merge3Vias(&direita,tamDireita);

	//Merge final
	merge(&(*livro),esquerda,meio,direita,nLivros,tamEsquerda,tamMeio,tamDireita);

	free(esquerda);
	free(meio);
	free(direita);

	return *livro;

}

int main(int argc, char *argv[]){

    int nLivros = 0;
	LIVRO *livros = NULL,*livrosOrdenados = NULL;
	scanf("%d",&nLivros);

	cadastrarLivros(&livros,nLivros);

	imprimirPrecosLivros(livros,nLivros);

	livrosOrdenados = merge3Vias(&livros,nLivros);

	printf("\n");
	imprimirListaLivros(livrosOrdenados,nLivros);

	desalocarListaLivros(livrosOrdenados,nLivros);

    return 0;
}