/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv){

    // número a ser conferido os bytes
    long int n;

    // leitura do número
    scanf("%ld",&n);

    // tranferimos o endereço do número lido para um unsigned
    // char lhe conferindo cobertura da tabela ascii para conversão correta
    unsigned char *endereco = (unsigned char *)&n;
    
    // percorremos os 8 bytes imprimindo os endereços
    for(int i = 0; i < 8 ; i++){ 
        printf("%x \n",endereco[i]);
    }

    return 0;
}