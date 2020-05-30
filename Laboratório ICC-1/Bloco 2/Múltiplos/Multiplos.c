/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

int main(int argc, char **argv){

    //qtd --> número de termos
    // n1 e n2 --> números para serem analisados os múltiplos
    // cont --> contador
    //mult --> número candidato a ser múltiplo
    int qtd, n1, n2, cont = 0, mult = 0;

    // Obtenção dos dados
    scanf("%d %d %d", &qtd, &n1, &n2);
    
        // Serão analisados n números (qtd) que forem digitados e
        // enquanto o contador não atingir n, ele continuará realizando
        //a iteração
        while (cont < qtd){
           
           // Se for múltiplo de n1 ou n2 será exibido na tela
            if(mult % n1  == 0 || mult % n2 == 0){
                printf("%d \n", mult);
                // o contador aumenta um somente se achar um múltipo 
                cont = cont + 1;
            }
            
            // o múltiplo é incrementado 1
            mult = mult + 1;
        }

    return 0;
}