/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

int main(int argc, char **argv){
	
	// vetor com 31 posicoes 
	int vetor[31], i;
	
	// leitura dos valores
	for (i = 0; i < 31; i++){
        scanf("%d", &vetor[i]);
	}
	
	// checar se são divisiveis usando o operador mod
	for(i = 0; i < 30; i++){
	 
		if(vetor[i] % vetor[30] == 0){
			printf("%d \n",vetor[i]);
		}
	}
			
	return 0;
}