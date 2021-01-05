/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

    Estrutura de dados (arvore binária de busca) desenvolvida parcialmente na aula de algoritmos,
	a adaptação para este trabalho foi feita por mim

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Includes/arvoreBinariaBusca.h"

typedef struct _no NO;
struct _no {
    ITEM *item;
    NO *esq;
    NO *dir; 
};

struct _arvore_binaria_busca{
    NO *raiz;
    int profundidade;
};

/* Função para criar uma instancia de arvore binária */
ABB *criar_abb(void) {
    ABB *arvore = (ABB*) malloc(sizeof(ABB));

    if (arvore != NULL) {
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }

    return arvore;
}

/* Função para escrever o percurso em pré ordem de uma arvore binaria
    Raiz -> Esquerda -> Direita
*/
void abb_preordem(NO *raiz) {
    if (raiz != NULL) {
        imprimirItem(raiz->item);
        abb_preordem(raiz->esq);
        abb_preordem(raiz->dir);
    }
}

/* Função para escrever o percurso em ordem de uma arvore binaria
    Esquerda -> Raiz -> Direita
*/
void abb_emordem(NO *raiz) {
    if (raiz != NULL) {
        abb_emordem(raiz->esq);
        imprimirItem(raiz->item);
        abb_emordem(raiz->dir);
    }
}

/* Função para escrever o percurso em pos ordem de uma arvore binaria
    Esquerda -> Direita -> Raiz
*/
void abb_posordem(NO *raiz) {
    if (raiz != NULL) {
        abb_posordem(raiz->esq);
        abb_posordem(raiz->dir);
        imprimirItem(raiz->item);
    }
}

void abb_imprimir(ABB *abb){
    printf("Imprimindo em pre ordem\n");
    abb_preordem(abb->raiz);
    printf("\nImprimindo em ordem\n");
    abb_emordem(abb->raiz);
    printf("\nImprimindo em pos ordem\n");
    abb_posordem(abb->raiz);
}

/*Função para criar novo no*/
NO *abb_cria_no(ITEM *item){
    NO *no = (NO *)malloc(sizeof(NO));

    no->item = item;

    no->esq = NULL;
    no->dir = NULL;

    return no;
}

//Função de inserir no na arvore binaria de busca
NO *abb_inserir_no(NO *raiz, ITEM *item){
    if (raiz == NULL){
        raiz = abb_cria_no(item);
    }else if (strcasecmp(itemGetKey(item),itemGetKey(raiz->item))>0){
        raiz->dir = abb_inserir_no(raiz->dir, item);
    }else if (strcasecmp(itemGetKey(item),itemGetKey(raiz->item))<0){
        raiz->esq = abb_inserir_no(raiz->esq, item);
    }
    return (raiz);
}

// Função para inserir um item na arvore binaria de busca
boolean abb_inserir(ABB *abb,ITEM *item){
    return((abb->raiz = abb_inserir_no(abb->raiz,item)) != NULL);
}


//Função para busca recursiva
ITEM *abb_busca_recursiva(NO *raiz, char *chave){
    
    //Raíz nula
    if(raiz == NULL){
        return NULL;
    }else{
        //Se nao for nula
        if(strcasecmp(chave,itemGetKey(raiz->item))==0){ //Achou a chave logo na raiz
            return (raiz->item);
        }
        else{
            if(strcasecmp(chave,itemGetKey(raiz->item))<0){ //A chave buscada é menor, buscamos a esquerda
                return (abb_busca_recursiva(raiz->esq,chave));
            }
            else{
                return (abb_busca_recursiva(raiz->dir,chave));//A chave buscada é maior, buscamos a direita
            }
        }
    }
}

// Função de busca
ITEM *abb_busca(ABB *abb,char *chave){
    return (abb_busca_recursiva(abb->raiz,chave));
}

//Função de troca maxima
void troca_max_esq(NO *troca,NO *raiz, NO *ant){
    if (troca->dir != NULL){
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }
    if (raiz == ant){
        ant->esq = troca->esq;
    }else{
        ant->dir = troca->esq;
    }

    raiz->item = troca->item;
    free(troca);
    troca = NULL;
}

//Remoçaõ do no em arvore binaria de busca
boolean abb_remover_aux(NO **raiz, char *chave){
    NO *p;
    if (*raiz == NULL){
        return (FALSE);
    }
    if (strcasecmp(chave,itemGetKey((*raiz)->item))==0){

        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL){ 
            /*Caso	1	se	resume	ao	caso	2:	há	um	filho	ou	nenhum*/
            p = *raiz;
            if ((*raiz)->esq == NULL){
                *raiz = (*raiz)->dir;
            }else{
                *raiz = (*raiz)->esq;
            }
            deletarItem(&p->item);
            free(p);
            p = NULL;

        }else{
            /*Caso	3:	há	ambos	os	filhos*/
            troca_max_esq((*raiz)->esq, (*raiz), (*raiz));
        }
        return (TRUE);

    }else if (strcasecmp(chave,itemGetKey((*raiz)->item))<0){
        return abb_remover_aux(&(*raiz)->esq, chave);
    }else{
        return abb_remover_aux(&(*raiz)->dir, chave);
    }
}

//Função para remover no
boolean abb_remover(ABB *abb, char *chave){
    if (abb != NULL)
        return (abb_remover_aux(&abb->raiz, chave));
    return (FALSE);
}

/*Função para calcular profundidade da arvore binaria de busca*/
int abb_profundidade_recursiva(NO *no){
    if(no == NULL){
        return -1;
    }

    int alturaE = abb_profundidade_recursiva(no->esq);
    int alturaD = abb_profundidade_recursiva(no->dir);

    if(alturaE > alturaD){
        return alturaE + 1;
    }else{
        return alturaD + 1;
    }
}

int abb_profundidade(ABB *abb){
    return abb_profundidade_recursiva(abb->raiz);
}

/*Função para contar quantidade de nos */
int abb_contar_nos_recursiva(NO *no){
    int count = 1;

    if(no->esq != NULL)
        count += abb_contar_nos_recursiva(no->esq);
    
    if(no->dir != NULL){
        count += abb_contar_nos_recursiva(no->dir);
    }
    return count;
}

int abb_contar_nos(ABB *abb){
    return abb_contar_nos_recursiva(abb->raiz);
}

//Função q checa se arvore binaria de busca é perfeitamente balanceada ou não
boolean abb_checar_balanceamento_perfeito_recursivamente(NO *no,int profundidade,int nivel){
    if(no == NULL){
        return TRUE;
    }

    //Se chegamos na folha precisamos ver se ambos nao tem filhos
    if(no->esq == NULL && no->dir == NULL){
        return (profundidade == nivel);
    }

    //Caso haja diferença, não é perfeitamente balanceada
    if(no->esq == NULL || no->dir == NULL){
        return FALSE;
    }

    //Vamos checar o no esquerdo e o direito
    return abb_checar_balanceamento_perfeito_recursivamente(no->esq,profundidade,nivel+1) &&
           abb_checar_balanceamento_perfeito_recursivamente(no->dir,profundidade,nivel+1);
}

void abb_checar_balanceamento_perfeito(ABB *abb){
    
    int profundidade = abb_profundidade(abb);
    if (abb_checar_balanceamento_perfeito_recursivamente(abb->raiz,profundidade,0) == TRUE){
        printf("é perfeitamente balanceada!\n");
    }else{
        printf("não é perfeitamente balanceada :( \n");
    }
}

/*Função para apagar arvore*/
void apagar_arvore(NO **raiz){
    if(*raiz != NULL){
        apagar_arvore(&(*raiz)->esq);
        apagar_arvore(&(*raiz)->dir);
        deletarItem(&(*raiz)->item);
        free(*raiz);
        *raiz = NULL;
    }
}

void deletar_abb(ABB **abb){
    apagar_arvore(&(*abb)->raiz);
    free(*abb);
    *abb = NULL;
}