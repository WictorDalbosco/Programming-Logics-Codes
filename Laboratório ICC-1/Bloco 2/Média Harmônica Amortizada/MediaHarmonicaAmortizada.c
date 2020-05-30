/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

int main(int argc, char **argv){
	
	// n --> numero de notas a serem atribuidas
	// i --> contador para uso no 'for'
	// media --> media final harmonica amortizada
	// notaN --> nota de cada prova
	// divisor --> a soma do divisor
	int n, i;
	double media, notaN, divisor = 0;
	
	scanf("%d", &n);
	
	// vetor de tamanho n
	double vetor[n];
	
	// recolhendo as notas e calculando o divisor
	// da fórmula de média harmonica
	for (i = 0; i < n; i++){
        scanf("%lf", &vetor[i]);
        // printf("%d \n", vetor[i]);
        notaN = vetor[i];
		divisor = divisor + (1 / (notaN + 1));
		// printf("%lf \n",divisor);
	}
	
	// com todos os valores recolhidos agora
    // é so calulcar a média
	media = (n / divisor) - 1;
	
	printf("%0.2lf", media);
		
	return 0;
}