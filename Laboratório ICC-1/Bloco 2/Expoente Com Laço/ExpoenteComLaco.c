/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

int main(int argc, char **argv){
	// a --> Base
	// b --> expoente
	//i --> contador
	//resultado --> resultado da exponenciação
	float a, b, resultado;
	int i;
	
	scanf("%f", &a);
	scanf("%f", &b);
	
	// variavel resultado recebe o valor de a para ser atribuida durante o laço
	resultado = a;
	
	//no laço o contador vai até b para que o for nao ultrapasse o valor do expoente
	for(i = 1; i < b ; i++){
		//A operação multiplica um por vez o fator em questão no laço e atribui ao resultado
	    resultado = resultado * a;
		
	}
	
	// Se b for igual a zero a soulução no for nao contempla essa conta devido ao contador if
	// começar em 1, ou seja, o for não irá ser inicializado nesse caso
	if(b == 0){
	    resultado = 1;
	}
	
	printf("%0.4f", resultado);
	
return 0;
}