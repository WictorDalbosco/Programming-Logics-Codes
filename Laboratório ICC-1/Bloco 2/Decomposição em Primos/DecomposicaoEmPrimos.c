/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

int main(int argc, char **argv){

    //n --> o número inserido
    // fator --> número fator de n, começando em 2
    // mult --> multiplicidade do fator
    int n, fator = 2, mult;

    //Leitura do número
    scanf("%d", &n);

    // primeiro while para fazer divisões ate o número chegar a 0
    while(n > 1){
        // sempre quando se for iniciar um novo fator a multiplicidade
        // deve ser zerada
        mult = 0;
        // enquanto for divisível pelo fator continuar dividindo
        while(n % fator == 0){
            // incrementar a multiplicidade
            mult ++;
            //dividir o valor pelo fator
            n = n / fator;
        }
        // se a multiplicidade for diferente de 0 então imprima o fator e sua multiplicidade
        if(mult != 0){
            printf("%d %d \n", fator, mult);
        }
        //incrementa o fator para a próxima divisão
        fator ++;
    }

    return 0;
}