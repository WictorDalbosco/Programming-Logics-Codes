/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

int main(){
    
    //n --> numero de elementos do vetor
    //i e j --> contadores para manipular os vetores
    //temp --> variavel temporaria de alocação de valores
    int n, i, j, temp;

    scanf("%d", &n);
    
    // vetor[] --> usado para guardar a sequencia de valores digitada
    int vetor[n];

   // leitura de valores 
    for (i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
	}
    
    // usando duas estruturas do tipo 'for' é possível navegar pelos vetores 
    // de forma a ordenar os valores do maior pelo menor usando o método 'bubble sort'
    // enquanto um vetor de indice 'i' vai ate o penúltimo valor de seu vetor de maneira a
    // fixar o maior valor no último índice e repetindo as etapas até tudo estar 
    // devidamente organizado
    for (i = 0 ; i < n - 1; i++){
        for (j = 0 ; j < n - i - 1; j++){
            if (vetor[j] > vetor[j+1]){
            temp       = vetor[j];
            vetor[j]   = vetor[j+1];
            vetor[j+1] = temp;
            }
        }
    }
	
	//Imprimindo o maior e menor valor
    printf("max: %d \n",vetor[n - 1]);
    printf("min: %d \n",vetor[0]);

  return 0;
}