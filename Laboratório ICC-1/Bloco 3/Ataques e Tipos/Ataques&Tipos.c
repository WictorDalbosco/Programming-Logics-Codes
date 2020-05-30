/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Struct de ataque
struct Ataque{
    int poder;
    int tipo;
};

typedef struct Ataque ATAQUE;

//Alocar matriz na heap
float **alocarMatriz(int ordem){
    
    //Usando as funções da biblioteca stdlib.h (malloc) podemos alocar
    // dinamicamente matrizes na heap, primeiro como um vetor de linhas
    float **matriz = (float **) malloc (ordem * sizeof(float *));

    // Em seguida alocamos as colunas como sendo vários vetores associados as linhas
    for(int i = 0; i < ordem; i++){
        matriz[i] = (float *) malloc (ordem * sizeof(float));
    } 
    
    if (matriz == NULL){
        abort();
    }
    
    return matriz;
}

//Desalocando a matriz da heap 
void desalocarMatriz(float **matriz, int ordem){
    int i;

    for(i=0; i < ordem; i++){
        free(matriz[i]); 
    }

    free(matriz);
}

void inserirMatriz(float **matriz, int ordem){

    for(int i = 0; i < ordem; i++){
        for(int j = 0; j < ordem; j++){
            scanf("%f",&matriz[i][j]);
        }
    }
}

ATAQUE *inserirAtaque(ATAQUE *listaAtaques, int *qtdAtaques){
    //Contadores e auxiliares para recolher o poder e tipo
    int i = 0, aux1 = 0, aux2 = 0;

    while(scanf("%d",&aux1) && aux1 >= 0){
        i++;
        //Pegamos os atributos do poder
        scanf("%d",&aux2);
        //Se um deles form -1 podemos sair
        if(aux1 == -1 || aux2 == -1 ){ 
            break;
        } else {
            //Alocamos o poder na lista de ataques
            listaAtaques = (ATAQUE *)realloc(listaAtaques,i * sizeof(ATAQUE));
            listaAtaques[i-1].poder = aux1;
            listaAtaques[i-1].tipo = aux2;
            *qtdAtaques = *qtdAtaques + 1;
        } 
    }
    //Retornamos a lista
    return listaAtaques;
}

//Vamos verificar qual poder usar
void verificarAtaque(ATAQUE *listaAtaques,int qtdAtaques, float **matriz, int ordem){
    int tipoInimigo, indiceAtaque = 0;
    float ataqueFinal = 0;
    scanf("%d",&tipoInimigo);

    //Uma observação : Se fizesse desse jeito seria uma maneira mais desafiadora e um pouco mais intuitiva do que o exercício realmente quer
    // já que teríamos que buscar qual o melhor ataque na lista, não dependendo do usuário digitar na ordem :)
    /*for(int k = 0; k < qtdAtaques; k++){
        //Houve match entre o tipo de inimigo e o tipo de ataque que iremos usar
        if(listaAtaques[k].tipo == tipoInimigo){
            multiplicador = listaAtaques[k].poder;
        }
    }*/

    //Percorremos a matriz de tipos e ataques percorrendo pela coluna onde está o tipo de inimigo desejado
    for(int j = 0; j < ordem; j++){
        //Checagem do maior valor de ataque
        if ((matriz[j][tipoInimigo] * listaAtaques[j].poder) > ataqueFinal){ //Se usassemos a maneira descrita aqui teríamos o produto com o multiplicador
            //Temos então o melhor ataque o índice dele
            ataqueFinal = matriz[j][tipoInimigo] * listaAtaques[j].poder;
            indiceAtaque = j;
        }
    }

    printf("O melhor ataque possui indice %d e dano %0.2f\n",indiceAtaque,ataqueFinal);

}

int main(int argc, char **argv){
    //Matriz de ordem M
    int ordem, qtdAtaques = 0;
    float **matriz;

    //Pegando a ordem da matriz
    scanf("%d",&ordem);

    //Alocando na heap
    matriz = alocarMatriz(ordem);

    //Colocando os dados na matriz
    inserirMatriz(matriz,ordem);

    //Criando um struct de ataques
    ATAQUE *listaAtaques = NULL;

    //Recolhaneod a lista de ataques
    listaAtaques = inserirAtaque(listaAtaques, &qtdAtaques);

    //Verificando qual ataque usar
    verificarAtaque(listaAtaques,qtdAtaques,matriz,ordem);

    //Desalocando a matriz
    desalocarMatriz(matriz,ordem);

    //Desalocando o struct
    free(listaAtaques);

    return 0;
}