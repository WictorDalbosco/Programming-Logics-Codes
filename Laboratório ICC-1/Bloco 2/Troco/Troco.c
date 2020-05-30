/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

// Função que calcula o troco por valores referenciados
void troco( int *cents, int *valor1, int *valor50, int *valor25, int *valor10, int *valor5, int *valor1cent){

    //Utilizando o operador mod conseguimos receber os restos das divisões
    // e assim calcular o troco corretamente, e mudar os valores nas variaveis no código main
    // já que estamos usanto ponteiros para referenciar os valores
    *valor1 = *cents / 100;
    *cents = *cents % 100;

    *valor50 = *cents/ 50;
    *cents = *cents % 50;

    *valor25 = *cents / 25;
    *cents = *cents % 25;

    *valor10 = *cents/ 10;
    *cents = *cents % 10;

    *valor5 = *cents / 5;
    *cents = *cents % 5;

    *valor1cent = *cents/ 1;

}

int main(int argc, char **argv){

    // Cents --> valor de centavos recebidos
    // cada variável valor representa uma moeda diferente
    int cents, valor1 = 0, valor50 = 0, valor25 = 0, valor10 = 0, valor5 = 0, valor1cent = 0;

    scanf("%d", &cents);

    // calculo do troco por referência
    troco(&cents,&valor1, &valor50, &valor25, &valor10, &valor5, &valor1cent);

    printf("O valor consiste em %d moedas de 1 real\n",valor1);
    printf("O valor consiste em %d moedas de 50 centavos\n",valor50);
    printf("O valor consiste em %d moedas de 25 centavos\n",valor25);
    printf("O valor consiste em %d moedas de 10 centavos\n",valor10);
    printf("O valor consiste em %d moedas de 5 centavos\n",valor5);
    printf("O valor consiste em %d moedas de 1 centavo\n",valor1cent);
    
    return 0;
}
