/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

    Estrutura de dados (arvore binária de busca) desenvolvida parcialmente na aula de algoritmos,
	a adaptação para este trabalho foi feita por mim

*/

#ifndef ARVORE_H
    #include "item.h"
    #define ARVORE_H

    #define boolean int
    #define TRUE 1
    #define FALSE 0
    
    #define TAM 100 
    #define ERROR -32000

    //#define FILHO_ESQ 0
    //#define FILHO_DIR 1

    typedef struct _arvore_binaria_busca ABB;
    
    ABB *criar_abb(void);
    void abb_imprimir(ABB *abb);
    boolean abb_inserir(ABB *abb,ITEM *item);
    ITEM *abb_busca(ABB *abb, char *chave);
    boolean abb_remover(ABB *abb, char *chave);
    int abb_profundidade(ABB *abb);
    int abb_contar_nos(ABB *abb);
    void deletar_abb(ABB **abb);
    void abb_checar_balanceamento_perfeito(ABB *abb);

#endif