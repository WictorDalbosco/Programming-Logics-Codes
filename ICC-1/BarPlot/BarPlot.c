/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
    
    //qtdBarras --> número de barras do gráfico
    // qtdElementos --> quantidade de elementos q serão digitados
    // elemento --> os elementos que serão transformados em barra
    int qtdBarras, qtdElementos, i = 0,elemento;

    scanf("%d", &qtdBarras);
    scanf("%d", &qtdElementos);
    
    //Alocando o vetor na heap
    int *vet = (int *) calloc (qtdBarras, sizeof(int));
    
    //Lendo todos os valores q serão armazenados por posição
    while (i < qtdElementos){
        scanf("%d", &elemento);
        for (int j = 0; j < qtdBarras; j++){
            //Se na posição for o mesmo elemento q o índice, é incrementado o valor do mesmo
            if (j == elemento){
                vet[j]++;
            }
            
        }
        //Agora passamos para o próximo número a ser analisado
        i++;     
    }
    
    //Percorrendo o vetor
    for(int i = 0; i < qtdBarras; i++){
        printf("%d - ",i);
        
        //Preenchendo as posições com '#' conforme o número de cada posição
        while(vet[i]--){
            printf("#");
        }
        printf("\n");
    }

    // liberando o vetor
    free(vet);

    return 0;
}