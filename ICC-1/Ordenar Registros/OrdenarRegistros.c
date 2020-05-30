/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Definindo um struct do tipo Filme
struct Register {
    char *name;
    int numero;
}; 

typedef struct Register REGISTER;

//FUNÇÃO READLINE
char *readLine(FILE *stream) {

    scanf(" ");

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

	} while (string[pos-1] != '\n' && string[pos- 1] != '\r' && !feof(stream));

    if(string[pos - 1] == ' '){
        string[pos -1] = '\0';
    }

    //Limpamos o \n que vier incluido no stream
	string[pos-1] = '\0';

    //Realocamos para o novo tamanho da string
	string = (char *) realloc(string, pos);
	
	return string;

}

char *chopString(char *string, int *numero){

    //Temos o tamanho da string para podermos manipulá-la
    int tamString = strlen(string);
    //Usaremos o i como contador interno da string e j para servir se base 10 na multiplicação do dado numérico
    int i = tamString, j = 1;
    *numero = 0;
    
    //Tirando eventuais espaços do final da string
    if(string[i-1] == ' '){
        i = i-2;
    }

    //Começando a leitura da string de trás para frente
    while (string[i] != ' '){
        if(string[i] == '\0'){
            i--;
            continue;
        }
        //Se acharmos um "-" significa que o número é negativo
        if(string[i] == '-'){
            *numero = *numero * (-1);
            i--;
            continue;
        }
        //Já para o número do dado vamos tirar 48 para corresponder a tabela ascii e multiplicar pela base 10 para 
        // termos o número correto salvo
        *numero = (*numero + (((int)string[i]-48)*j));
        j = j * 10;
        i--; 
    }
    //Chegamos no último caracter da frase então aumentamos um para adicionar o \0
    i++;

    //Limpamos o \n incluido
    string[i]='\0';
    
    //Desalocando os números e deixando só o nome
    string = (char *)realloc(string, (i+1) * sizeof(char));
    
    
    return string;
    
}


REGISTER* alocarDados(REGISTER *registerList, int *qtdRegistros){

    int i = 0;

    while(!feof(stdin) ){
         
        i++;
        //Alocou um registro
        registerList=(REGISTER *)realloc(registerList,i * sizeof(REGISTER));
        //Leu a linha completa
        registerList[i-1].name = readLine(stdin);
        //printf("Vamos ler depois de cada readline: %s\n",registerList[i-1].name);
        //Cortou em nome, e por referência, já conseguiu o ano de lançamento
        registerList[i-1].name = chopString(registerList[i-1].name,&registerList[i-1].numero);
         
    }
    
    *qtdRegistros = i;
    return registerList;   
}

REGISTER * ordenarAlfabeticamente(REGISTER *registerList, int qtdRegistros){
    REGISTER *orderedList = (REGISTER *)calloc(qtdRegistros,sizeof(REGISTER));
    
    //Bubble sort alfabetico
    for(int i = 0; i < qtdRegistros; i++){
        for(int j = 0; j < qtdRegistros - 1; j++){
            if(strcmp(registerList[j].name,registerList[j +1].name) > 0){
                orderedList[j] = registerList[j];
                registerList[j] = registerList[j+1];
                registerList[j+1]=orderedList[j];
            }
        }
    }

    free(orderedList);
    return registerList;
    
    
}

REGISTER * ordenarNumericamente(REGISTER *registerList, int qtdRegistros){
    //Criamos uma struct para auxiliar a ordenação
    REGISTER *orderedList = (REGISTER *)calloc(qtdRegistros,sizeof(REGISTER));
    
    //Bubble sort de buenas
    for(int i = 0; i < qtdRegistros; i++){
        for(int j = 0; j < qtdRegistros - 1; j++){
            if(registerList[j].numero > registerList[j+1].numero){
                orderedList[j] = registerList[j];
                registerList[j] = registerList[j+1];
                registerList[j+1]=orderedList[j];
            }
        }
    }

    //Liberamos depois ela
    free(orderedList);

    return registerList;
}

int main(int argc, char *argv[]){

    //1 Ordenar alfabeticamente
    //2 Ordenar por numero inteiro
    int operacao, qtdRegistros = 0;

    //Lendo a operaçao que será feita 
    scanf("%d",&operacao);

    //Struct de registros
    REGISTER *registerList = NULL;

    registerList = alocarDados(registerList, &qtdRegistros);

    //Vamos ordenar
    switch (operacao){
        //Alfabeticamente
        case 1:
            registerList = ordenarAlfabeticamente(registerList,qtdRegistros);
        break;

        //Numéricamente
        case 2:
            registerList = ordenarNumericamente(registerList,qtdRegistros);
        break;
    }

    //Escrevendo na ordem desejada
    for(int i = 0; i < qtdRegistros; i++){
        printf("%d\t%s\n",registerList[i].numero,registerList[i].name);
    }

    //Liberando o ponteiro do name
    for (int i = 0; i < qtdRegistros; i++){
      free(registerList[i].name);
    }
    
    //Liberando a lista de structs
    free(registerList);

    return 0;
}