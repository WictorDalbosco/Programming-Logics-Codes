/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NLINHA 3
#define NCOLUNA 3

//Alocar matriz na heap
char **alocarMatriz(int nLinhas, int nColunas){
    
    int cont = 1;

    //Usando as funções da biblioteca stdlib.h (calloc) podemos alocar
    // dinamicamente matrizes na heap, primeiro como um vetor de linhas
    char **matriz = (char **) calloc (nLinhas, sizeof(char *));

    // Em seguida alocamos as colunas como sendo vários vetores associados as linhas
    for(int i = 0; i < nLinhas; i++){
        matriz[i] = (char *) calloc (nColunas, sizeof(char));
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
void desalocarMatriz(char **matriz){
    int i;

    for(i=0; i < NLINHA; i++){
        free(matriz[i]); 
    }

    free(matriz);
}

//Imprime estado a cada jogada
void imprimirEstado(char **matriz){

    int i, j;

    for(i = 0; i < NLINHA; i++){
        j = 0; 
        printf("%c   |%c   |%c   |\n----+----+-----\n", matriz[i][j], matriz[i][j+1],matriz[i][j+2]);
    }
}

int verificarGanhador(char **matriz, int turno, char jogador){
    int i, j, ganhou = 0;

    //Checando ganhadores

    //Checar por linha
    for(i = 0; i < NLINHA; i++){ 
        j = 0;
        if(matriz[i][j] == matriz[i][j+1] && matriz[i][j] == matriz[i][j+2]){
            ganhou++;
        }
    }
    
    //Checando por coluna
    for(j = 0; j < NCOLUNA; j++){
        i = 0;
        if(matriz[i][j]== matriz[i+1][j] && matriz[i][j] == matriz[i+2][j]){
            ganhou++;
        }
    }
    
    //Checar por diagonal
    
    //Diagonal principal
    if(matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]){
        ganhou++;
    }
    
    //Diagonal secundaria
    if(matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0]){
        ganhou++;
    }
    
    

    if(ganhou != 0){
        printf("Fim do jogo! O jogador %c venceu!", jogador);
        desalocarMatriz(matriz);
        exit(0);

    }else{
        return 0;
    }    
}

int conferirJogada(char **matriz, int jogada){
    
    //O contador serve para marcar caso ninguem tenha preenchido a posição
    int i,j, contador;

    for(i = 0; i < NLINHA; i++){   
       for(j = 0; j < NCOLUNA; j++){
           //é adicionado um terminador de string
           if(matriz[i][j] == jogada + '0'){
               contador++;
           }
       }
    }

    if(contador == 0){
        // O espaço ja foi escolhido
        return 0;
    }else{
        //Não foi jogado nesse posição, e pode prosseguir
        return 1;
    }
}

void computarJogada(char **matriz, int jogada, char jogador){
    int i,j;
    //Inserindo X ou O no lugar desejado
    for(i = 0; i < NLINHA; i++){   
       for(j = 0; j < NCOLUNA; j++){
           if(matriz[i][j] == jogada + '0'){
               matriz[i][j]= jogador;
           }
       }
    }
}


int main(int argc, char **argv){

    // declaração do ponteiro da matriz na stack
    char **matriz;

    // turno --> se for impar = X, se for par = O;
    //jogada --> qual número o jogador quer inserir
    int turno = 1, jogada = 0;
    
    //Jogador que fez a jogada
    char jogador;

    //Alocando a matriz na heap através da função alocarMatriz
    matriz = alocarMatriz(NLINHA,NCOLUNA);

    //Imprimos o estado inicial da matriz
    imprimirEstado(matriz);

    printf("Jogo da velha!\n");

    //Somente é possível ter 9 turnos ou o jogo acabar antes
    while(turno <= 9){

        //Dependendo do turno teremos a vez do jogador X ou do jogador O
        if(turno % 2 == 0){
            jogador = 'O';
        }else{
            jogador = 'X';
        }

        printf("Escolha um número para jogar, jogador %c!\n", jogador);

        //Recebemos a jogada
        scanf("%d", &jogada);

        //Usando a funçao de conferir, checamos se a jogada é válida
        while (conferirJogada(matriz,jogada) == 0){
            printf("Jogada inválida! Escolha outra casa.\n");
            scanf("%d", &jogada);
        }

        //Se tudo deu certo podemos computar a jogada na matriz
        computarJogada(matriz,jogada, jogador);

        //Ao final da jogada imprimimos a matriz
        imprimirEstado(matriz);
        
        //Verificar se alguém ganhou
        verificarGanhador(matriz,turno, jogador);
        
        turno++;

    }

    printf("Deu velha!");

    //Desalocar matriz
    desalocarMatriz(matriz);

    return 0;
}