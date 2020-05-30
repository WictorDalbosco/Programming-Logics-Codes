/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv){

    // Vetor de direções em uma string
    char direcoes[200] = {0};
    
    //'d' e 'e' são o número de vezes que o robo virou para a direita e esquerda
    //final --> para onde estará apontando, numericamente
    //tam --> tamanho da string
    int d = 0, e = 0, final = 0, tam;
    
   //recolhendo as direçoes
    scanf("%s",direcoes);
    
    //calculando o tamanho do vetor
    tam = strlen(direcoes);
    
    // navegando pelo vetor de direçoes
    for(int i = 0; i < tam; i++){
        // se ele virou pra direita, é somado 1 a 'd'.
        if(direcoes[i] == 'D'){
            //final++;
            d ++;
        // se ele virou para a esquerda, é somado 1 a 'e'.
        }else if(direcoes[i] == 'E'){
            //final--;
            e++;
        }
    }
    
    //printf("%d \n",d);
    //printf("%d \n",e);
    
    //ele estará apontando para a direção dita pela diferença de vezes que 
    //virou para a direita pelo número de vezes que virou a esquerda
    final = (d - e);
    
    // agora, já que ele tem 4 direçoes disponíveis para virar, somente
    //pegamos o resto da divisão por 4 e achamos a direção que ele estará apontando
    final = final % 4;
    
    
    // se for negativo sera somado 4 ao valor final, garantindo que o resultado fique postivo
    if(final < 0){
      final += 4;  
    } 
        
    
    /*
                /\
                | Resto 0
                |
Resto 3 <--------------> Resto 1
                |
                |Resto 2
                \/
            
    */
        switch(final){
            case 0: printf("Norte");
            break;
            
            case 1: printf("Leste");
            break;
            
            case 2: printf("Sul");
            break;
            
            case 3: printf("Oeste");
            break;
            default: printf("Deu erro hein more");
            break;
        }
        
    return 0;
}
