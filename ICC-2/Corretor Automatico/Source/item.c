/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

    Estrutura de dados (arvore binária de busca) desenvolvida parcialmente na aula de algoritmos,
	a adaptação para este trabalho foi feita por mim

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Includes/item.h"

//O item é a palavra do dicionario
struct _item {
    char *key;
};

ITEM *criarItem(char *key) {
    ITEM *item;
    item = (ITEM *) malloc(sizeof(ITEM));
    
    if (item){
        item->key = (char *)calloc(strlen(key)+1,sizeof(char));
        strcpy(item->key,key);
    }
         
    return item;
}

boolean deletarItem(ITEM **item) {
    if (!item)
        return FALSE;

    free((*item)->key);
    free(*item);
    *item = NULL;

    return TRUE;
}

void imprimirItem(ITEM *item) {
    if (item)
        printf("%s\n", item->key);
    else
        printf("Item não existe");
}

char *itemGetKey(ITEM *item) {
    if (item)
        return item->key;
    
    exit(1);
}

boolean itemSetKey(ITEM *item, char *newKey) {
    if (!item)
        return FALSE;

    free(item->key);
    item->key = (char*)calloc(strlen(newKey)+1,sizeof(char));
    strcpy(item->key,newKey);
    return TRUE;
}