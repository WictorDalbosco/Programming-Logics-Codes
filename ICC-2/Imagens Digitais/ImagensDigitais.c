/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COLOR 255

typedef struct{
    int x;
    int y;
}PIXEL;

int **alocaImagem(int dimensao){
    int **imagem = (int **)calloc(dimensao,sizeof(int*));

    for (int i = 0; i < dimensao; i++){
        imagem[i] = (int *)calloc(dimensao,sizeof(int));
    }

    return imagem;  
}

void desalocaImagem(int **imagem,int dimensao){
    for (int i = 0; i < dimensao; i++){
        free(imagem[i]);
    }
    free(imagem);  
}

void preencheImagemAleatoriamente(int ***imagem,int dimensao){
    for (int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            (*imagem)[i][j] = rand() % 256;
        }
    } 
}

void printImagem(int **imagem,int dimensao){
    for (int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            printf("%d\t",imagem[i][j]);
        }
        printf("\n");
    }  
}

void escreverPGM(int **imagem,int dimensao,char *nomeArquivo){

    FILE *pArquivo = fopen(nomeArquivo,"wb");

    fprintf(pArquivo,"P2\n");

    fprintf(pArquivo,"%d %d\n",dimensao,dimensao);
    fprintf(pArquivo,"%d\n",MAX_COLOR);

    for (int i = 0; i < dimensao; i++){
        for (int j = 0; j < dimensao; j++){
            fprintf(pArquivo,"%d ",imagem[i][j]);
        }
        fprintf(pArquivo,"\n");
    }
    
    fclose(pArquivo);
}

void auxCriarImagemRecursiva(int **imagem, int dimensao,int x, int y, int T,int valorAnterior){

    if(x >= dimensao || x < 0 || y >= dimensao || y < 0) return;

    int diferenca = abs(valorAnterior - imagem[x][y]);
    if(diferenca == 0) return;

    if(diferenca <= T){
        imagem[x][y] = valorAnterior;
    }else{
        return;
    }

    //Vamos testar as 4 direçoes
    auxCriarImagemRecursiva(imagem,dimensao,x-1,y,T,imagem[x][y]); // Cima
    auxCriarImagemRecursiva(imagem,dimensao,x,y+1,T,imagem[x][y]); // Direita       
    auxCriarImagemRecursiva(imagem,dimensao,x+1,y,T,imagem[x][y]); // Baixo    
    auxCriarImagemRecursiva(imagem,dimensao,x,y-1,T,imagem[x][y]); // Esquerda

}

void criarImagemRecursiva(int **imagem, int dimensao,int x, int y, int T){
    int p = imagem[x][y];

    //Para tratar o primeiro caso
    if(x >= dimensao || x < 0) return;
    if(y >= dimensao || y < 0) return;

    //Vamos testar as 4 direçoes
    auxCriarImagemRecursiva(imagem,dimensao,x-1,y,T,p); // Cima
    auxCriarImagemRecursiva(imagem,dimensao,x,y+1,T,p); // Direita       
    auxCriarImagemRecursiva(imagem,dimensao,x+1,y,T,p); // Baixo    
    auxCriarImagemRecursiva(imagem,dimensao,x,y-1,T,p); // Esquerda

}

int main(int argc, char *argv[]){

    //As nomenclaturas seguem o padrão pedido pelo enunciado:

    //N = dimensão N x N da imagem
    //x = coordenada x que inicia a recursao de alteração na imagem
    //y = coordenada y que inicia a recursão de alteração na imagem
    //T = semente aleatória (???)
    int N,x,y,T,**imagemInicial = NULL;

    scanf("%d %d %d %d",&N,&x,&y,&T);

    srand(T);

    imagemInicial = alocaImagem(N);
    
    preencheImagemAleatoriamente(&imagemInicial,N);
    printImagem(imagemInicial,N);
    escreverPGM(imagemInicial,N,"inicial.pgm");

    criarImagemRecursiva(imagemInicial,N,x,y,T);

    printf("\n");
    printImagem(imagemInicial,N);
    escreverPGM(imagemInicial,N,"final.pgm");

    desalocaImagem(imagemInicial,N);

    return 0;
}