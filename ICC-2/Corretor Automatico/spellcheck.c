/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

	Estrutura de dados (arvore binária de busca) desenvolvida parcialmente na aula de algoritmos,
	a adaptação para este trabalho foi feita por mim

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./Includes/arvoreBinariaBusca.h"

//Função para ler linhas
char *readLine(FILE *stream) {
    scanf(" ");

	char *string = NULL;
	int pos = 0;
	
    do{
        string = (char *) realloc(string, pos+1);
		string[pos] = (char) fgetc(stream);
		pos++;

	} while (string[pos-1] != '\n' && !feof(stream));

	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	
	return string;

}

//Função para ler palavras a partir de um file
char *readWord(FILE *stream) {
    scanf(" ");

	char *string = NULL;
	int pos = 0;
	
    do{
        string = (char *) realloc(string, pos+1);
		string[pos] = (char) fgetc(stream);
		pos++;

	//Usando todos os caracteres especiais que foram discriminados no enunciado, sem usar a função isalpha
	} while (string[pos-1] != ' ' && string[pos-1] != '\n' && string[pos-1] != ',' && string[pos-1] != '.'
		  && string[pos-1] != '!' && string[pos-1] != '?'  && string[pos-1] != '"' && string[pos-1] != '#'  
		  && string[pos-1] != ';' && string[pos-1] != '@'  && string[pos-1] != ':'  && string[pos-1] != '('  
		  && string[pos-1] != ')' && string[pos-1] != '-'  && (int) string[pos-1] != 39 && (int) string[pos-1] != 151 && !feof(stream));

	if(pos >= 2 && string[pos - 2] == '\r'){
		string[pos - 2] = '\0';
	}

	string[pos-1] = '\0';
	string = (char *) realloc(string, pos);
	
	return string;

}


//Inserir palavra no dicionario dado um texto qualquer, sem repeti-las
void criarDicionario(ABB *dicionario, char *fileNameDicionario){
	
	FILE *fp = fopen(fileNameDicionario,"r");

	if(fp == NULL){
		printf("Arquivo de texto não encontrado!\n");
		exit(1);
	}

	while(!feof(fp)){

		char *aux = readWord(fp); //Lemos uma palavra do livro texto

		if(strcmp(aux,"\0")==0){ //Linha vazia então pulamos
			free(aux);
			continue;
		}
		//Para deixar em lowercase e nao correr risco de armazenar palavras iguais
		for(int i = 0; aux[i]; i++){
  			aux[i] = tolower(aux[i]);
		}
		
		//Não queremos repetir palavras entao buscamos no dicinario ao mesmo tempo que carregamos ele
		if(abb_busca(dicionario,aux) == NULL){
			abb_inserir(dicionario,criarItem(aux));
		}
		free(aux);
	}

	fclose(fp);
}

//Função que le tweets provindos de uma API que os fornce em uma linha
void lerTweets(ABB *dicionario,char *fileNameTweets){

	FILE *fp = fopen(fileNameTweets,"r");

	if(fp == NULL){
		printf("Arquivo de tweets não encontrado!\n");
		exit(1);
	}

	boolean entrou = FALSE;

	while(!feof(fp)){

		char *line = readLine(fp);
		
		//Procurando a linha q contem o tweet
		if(strstr(line,"\"text\": ") != NULL){
			entrou = TRUE;

			//Transformamos o tweet cheio de caracteres especiais em somente palavras utilizando isalpha dessa vez
			for (int i = 0; i < strlen(line); i++)
				if(!isalpha(line[i])) line[i] = ' ';
	
			char *token = strtok(line," ");

			while (token != NULL){
				//Procuramos a palavra no dicionário, se não encontrarmos, imprimimos ela da forma como foi lida no tweet
				if(abb_busca(dicionario,token)==NULL && strcmp(token,"text")!= 0) printf("%s ",token);
				token = strtok(NULL," ");
			}
			printf("\n");
		}

		free(line);
	}

	if (entrou==FALSE) printf("No tweets to check\n");

	fclose(fp);
}

int main(){

	//Arquivos que trablharemos nesse exercício
	char *fileNameDicionario = readLine(stdin); //Arquivo texto, em .txt (ASCII)
	char *fileNameTweets = readLine(stdin); //Arquivo de tweets .json (ASCII)
	
	//Criamos a estrutura de dados q usaremos: arvore binaria de busca
	ABB *dicionario = criar_abb();
	
	criarDicionario(dicionario,fileNameDicionario);

	lerTweets(dicionario,fileNameTweets);

	//Desalocamos todo o espaco que foi usado
	deletar_abb(&dicionario);
	free(fileNameDicionario);
	free(fileNameTweets);

	return 0;
}