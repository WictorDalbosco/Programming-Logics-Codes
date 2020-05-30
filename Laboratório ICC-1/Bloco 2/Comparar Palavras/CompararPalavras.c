/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h> 
#include <string.h>
#include <ctype.h>

// FUNÇÃO PARA SABER O VALOR DE UMA PALAVRA COM: A=1, B=2, ..., Z=26

int calculaValorPalavra(char *palavra, int tam){
    
    //i e j serão contadores
    // valor será o valor que a palavra tem
    // alfabeto representa vetor auxiliar para contagem
    int i,j, valor = 0;
    char alfabeto[27] =  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0'};
	char alfabetoA[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0'};
     
    // printf("%d %s \n",tam, palavra);
    
    // navegando pela palavra e pelo vetor auxiliar serão feitas comparações das letras
    // e determinar uma soma chamada de valor no codigo
    for(i = 0; i < tam ; i++){
        for(j = 0; j < 26; j++){
            if((palavra[i] == alfabeto[j]) || (palavra[i] == alfabetoA[j])){
                valor += j ;
            }
        }
    }

    // retorna o valor
    return valor;
    
}

// FUNÇÃO PARA COMPARAR QUAL PALAVRA TEM MAIS DE DETERMINADA LETRA

int comparaLetra(char *palavra, char letra,int tam){
	
	//i contador
	//qtd --> quantidade de vezes que repetea letra
	int i, qtd = 0;

	for (i = 0; i < tam; i++){
		if(palavra[i] == letra){
			qtd += 1;
		}
	}

	return qtd;
}

// FUNÇÃO PARA COMPARAR QUAL PALAVRA APARECE UMA LETRA PRIMEIRO

int qualGanha(char *palavra, char letra, int tam){

	//i é contador
	// posicao mostra em qual posição se encontra a letra desejada
	int i, posicao;

	// navegando pela palavra é possível encontrar a letra desejada e então
	// armazenar a posição que ela está, e ja podemos sair do laço com break
	for (i = 0; i < tam; i++){
		if(palavra[i] == letra){
			posicao = i;
			break;
		}
	}

	return posicao;
}

// DEIXA EM MINUSCULA
/*
char *toBaixa(char *palavra, int tam){
    int i;
    
    for(i = 0 ; i < tam ; i++ ){
	palavra[i] = tolower(palavra[i]);
    }
    
    return palavra;
}
*/



//COMEÇA A MAIN

int main(int argc, char **argv) {
    
   
	char p1[20] = {0}, p2[20] = {0}, letra;
	int op, tam1, tam2, tam, i;

	// leitura da opção
	scanf("%d", &op);
	
	// leitura das palavras
	scanf("%s %s",p1,p2);
	
	//Calcula o tamanho da palavra
	tam1 = strlen(p1);
	tam2 = strlen(p2);
	
	//Deixa tudo minúsculo
	p1[0] = tolower(p1[0]);
	p2[0] = tolower(p2[0]);

	switch(op){
		case 1:
			//compara os tamanhos das palavras 
			if (strlen(p1) > strlen(p2)){
				printf("1");
			}else if (strlen(p2) > strlen(p1)){
				printf("2");
			}else{
				printf("0");
			}
		break;
		case 2:
			//coloca em ordem alfabetica
			
			// Decidir qual tamanho usar para comparar as strings
			if(tam1 > tam2){
			    tam = tam1;
			}else if(tam2 > tam1){
			    tam = tam2;
			}else{ //são iguais
			    tam = tam1;
			}
			 
			// Para comparar as strings são verificados os valores delas de acordo com a tabela ascii em decimal ou seja
			// qual tem menor tamanho é uma letra mais abaixo no alfabeto
			for(i = 0; i < tam ; i++){
			    if(p1[i] != p2[i]){
			        if(p1[i]>p2[i]){
			            printf("2");
			        }else{
			            printf("1");
			        }
			        break;
			    }
			    // Se todas as lettras forem iguais (A mesma palavra) o contador atinge o tamanho
			    // e o processo pode parar
			    if(i == tam - 1){
			        printf("0");
			    }
			}
			
		/*	if (strcmp(p1,p2) > 0){
				printf("2");
			}else if(strcmp(p1,p2)> 0){
				printf("1");
			}else{
				printf("0");
			}
		*/
		
		break;
		case 3:
            //Calcula valor da palavras
            if(calculaValorPalavra(p1, tam1) > calculaValorPalavra(p2, tam2)){
                //printf("Palavra 1: %d", calculaValorPalavra(p1));
                printf("1");
            }else if(calculaValorPalavra(p1, tam1) < calculaValorPalavra(p2, tam2)){
                //printf("Palavra 2: %d", calculaValorPalavra(p2));
                printf("2");
            }else{
                //printf("São iguais");
                printf("0");
            }
            
		break;
		case 4:
			// compara quantas vezes uma palavra tem determinada letra
			scanf("%s",&letra);
			if(comparaLetra(p1, letra, tam1) > comparaLetra(p2, letra, tam2)){
				//printf("%s repete mais a letra %c \n",p1, letra);
				printf("1");
			}else if(comparaLetra(p1, letra, tam1) < comparaLetra(p2, letra, tam2)){
				//printf("%s repete mais a letra %c \n",p2, letra);
				printf("2");
			}else{
				printf("0");
			}
		    
		break;
		case 5:
			
			// Recebe a letra para a comparação
			scanf("%s",&letra);

			// Deixa em caixa baixa a letra
			letra = tolower(letra);

			// Chama a função para determinar qual delas tem a letra antes
			if(qualGanha(p1, letra, tam1) < qualGanha(p2, letra, tam2)){
				//printf("%s tem a letra %c primeiro \n",p1, letra);
				printf("1");
			}else if(qualGanha(p1, letra, tam1) > qualGanha(p2, letra, tam2)){
				//printf("%s tem a letra %c primeiro \n",p2, letra);
				printf("2");
			}else{
				printf("0");
			}
		break;
	} 
} 
