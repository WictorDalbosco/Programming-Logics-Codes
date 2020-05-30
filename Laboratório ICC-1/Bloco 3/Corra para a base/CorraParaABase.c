/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Alocar matriz na heap
int **alocarMatriz(int nLinhas, int nColunas){
    
    int cont = 1;

    //Usando as funções da biblioteca stdlib.h (calloc) podemos alocar
    // dinamicamente matrizes na heap, primeiro como um vetor de linhas
    int **matriz = (int **) calloc (nLinhas, sizeof(int *));

    // Em seguida alocamos as colunas como sendo vários vetores associados as linhas
    for(int i = 0; i < nLinhas; i++){
        matriz[i] = (int *) calloc (nColunas, sizeof(int));
    } 

    for(int i = 0; i < nLinhas; i++){
        for(int j = 0; j < nColunas; j++){
           matriz[i][j]= cont + '0';
           cont ++;
        }
    }
    
    if (matriz == NULL){
        abort();
    }
    
    return matriz;
}

//Desalocando a matriz da heap 
void desalocarMatriz(int **matriz, int nLinha, int nColuna){
    int i;

    for(i=0; i < nLinha; i++){
        free(matriz[i]); 
    }

    free(matriz);
}

int main(int argc, char *argv[]){

    //nLinha -> Número de linhas
    //nColuna -> Número de colunas
    //posX -> posição no eixo x
    //posY -> posiçao no eixo y
    int nLinha = 0, nColuna = 0, posX, posY;
    //Quanto ele pode se mover
    double movimento;
    //Qual a distância necessária para ganhar
    double dist;  

    scanf("%d %d", &nLinha,&nColuna);
    
    int **grade;

    //Alocandoa a matriz
    grade = alocarMatriz(nLinha,nColuna);

    scanf("%d %d %lf", &posX, &posY, &movimento);

    //Preenchendo a grade do mapa
    for(int i = 0; i <nLinha; i++){
        for (int j = 0; j < nColuna; j++){
            scanf("%d",&grade[i][j]);
            if (grade[i][j] == 1){
                dist = (pow((i - posX),2)+pow((j - posY),2));
                dist = sqrt(dist);
            }
        }  
    }

    //Se for maio escapou
    if(movimento >= dist){
        printf("Voce escapou!\n");
    }else{
        printf("Game Over!\n");
    }

    //Desalocou a matriz
    desalocarMatriz(grade, nLinha, nColuna);

    return 0;
}