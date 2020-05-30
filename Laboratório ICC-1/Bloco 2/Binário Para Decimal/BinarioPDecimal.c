/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h> 
#include <string.h> 

int main(int argc, char **argv) {
    
    //Sera feito implementação com um vetor de char de no máximo 30 caracteres completado com 
    // zeros para que não haja lixo estocado
    // o valor final será armazenado em 'decimal'
    // base --> o valor que é somado quando se está realizando a conversão ou seja é um valor
    // que representa uma potência de 2, começando em 2^0
    // i --> contador
    // tam --> tamanho do vetor de char que será inserido
	char binario[30] = {0} ; 
	int decimal = 0, base = 1, i, tam;

	// leitura do valor em binário atribuido para todos os índices do vetor
	scanf("%s",binario);
	
	//calcula o tamanho do vetor
	tam = strlen(binario);
	
	//printf("%d %s \n",tam, binario);
	 
	//O for começa no último valor que nesse caso é o valor menos significativo de base 1 e corre ao contrário pelo vetor
	for (i = tam - 1; i >= 0; i--) { 
		// se ele encontrar um valor '1' sera atribuído a soma da base 
		if (binario[i] == '1'){ 
		    // printf("Entrou no %d", i);
			decimal = decimal + base; 
			// printf(" Decimal: %d \n",decimal);
		    
		}
			//como estamos diante de uma conversão para decimal utiliza-se exponenciação de base 2 para realizar todos os 
			// calculos, ou seja, sempre multiplica-se por 2 a base anterior
			base = base * 2;
			// printf(" Base %d \n",base);		
	} 
	
	printf("%d",decimal);
} 
