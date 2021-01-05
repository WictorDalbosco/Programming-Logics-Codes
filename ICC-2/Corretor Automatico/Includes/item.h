/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

    Estrutura de dados (arvore binária de busca) desenvolvida parcialmente na aula de algoritmos,
	a adaptação para este trabalho foi feita por mim

*/


//Item: palavra armazenada no dicionario
#ifndef ITEM_H
    #define ITEM_H
    
    #define TRUE 1
    #define FALSE 0
    #define boolean int

    typedef struct _item ITEM;

    ITEM *criarItem(char *key);
    boolean deletarItem(ITEM **item);
    void imprimirItem(ITEM *item);
    char *itemGetKey(ITEM *item);
    boolean itemSetKey(ITEM *item, char *newKey);

#endif 