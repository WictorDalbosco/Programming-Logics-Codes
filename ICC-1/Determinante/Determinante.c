/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Alocar matriz na heap
int **alocarMatriz(int nLinhas, int nColunas){
    
    //Usando as funções da biblioteca stdlib.h (malloc) podemos alocar
    // dinamicamente matrizes na heap, primeiro como um vetor de linhas
    int **matriz = (int **) malloc (nLinhas * sizeof(int *));

    // Em seguida alocamos as colunas como sendo vários vetores associados as linhas
    for(int i = 0; i < nLinhas; i++){
        matriz[i] = (int *) malloc (nColunas * sizeof(int));
    } 
    
    if (matriz == NULL){
        abort();
    }
    
    return matriz;
}

//Desalocando a matriz da heap 
void desalocarMatriz(int **matriz, int nLinhas){
    int i;

    for(i=0; i < nLinhas; i++){
        free(matriz[i]); 
    }

    free(matriz);
}

//Função para calcular o determinante de uma matriz
int calculaDet(int ** mat, int ordem){

    // det --> determinante
    // dp --> diagonal principal
    // ds --> diagonal secundaria
    //cofator --> será utlizado para matrizes 3 x 3
    int det = 0,dp = 1, ds = 1, cofator = 0;
    
    switch (ordem){
        //Matriz 1 x 1
        case 1:    
            det = mat[0][0]; 
         break;

        //Matriz 2 x 2
        case 2:
            for(int i = 0; i < ordem; i++){
                for(int j = 0; j < ordem; j++){
                    if(i == j){
                        dp = dp * mat[i][j];
                    }else{
                        ds = ds * mat[i][j];
                    }
                }
            }
            //Calculo se dá pela difereça entra a diagonal principal e 
            // a diagonal secundaria
            det = dp - ds;
        break;
        
        //Matriz 3 x 3
        case 3:
            for(int i = 0; i < ordem; i++){
                //Utilizando o método da multiplicacção do cofator pelos subdeterminantes
                cofator = mat[0][i];
                det = det + cofator *(mat[1][(i + 1)%3]*mat[2][(i + 2)%3]
                      - mat[1][(i + 2)%3]*mat[2][(i + 1)%3]);
            }
        break;
    }
    
    return det;
}



int main(int argc, char **argv){

    //declaração de linha, determinante, coluna e ordem da matriz
    int linha, coluna, ordem, determinante;

    // declaração do ponteiro da matriz na stack
    int **matriz;

    // leitura dos dados de linha e coluna
    scanf("%d %d", &linha, &coluna);
    
    //Tratamento de erros como: matrizes negativas, de ordens diferentes de NxN
    // ou maiores do que 3x3, como especificado pelo exercício
    if( (linha != coluna) && (linha > 0 && coluna > 0) ){
        printf("A matriz de entrada nao possui determinante!\n");
    }else if(linha > 3 || coluna > 3 || linha < 1 || coluna < 1){
        printf("Entradas invalidas!\n");
    }else{
        
        ordem = linha;
    
        //Alocando a matriz na heap através da função alocarMatriz
        matriz = alocarMatriz(linha,coluna);
    
        // Recebendo os parâmetros da matriz para calcular o determinante
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                scanf("%d", &matriz[i][j]); 
            }
        }
    
        //Calculo do determinante por meio de uma função
        determinante = calculaDet(matriz, ordem);

        printf("O determinante da matriz de entrada equivale a %d e tem ordem %d \n",
                determinante, ordem);
    
        //Librando o espaço alocado na heap através da função desalocarMatriz
        desalocarMatriz(matriz, linha);
    
    }
    return 0;
}