/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/
#include <stdio.h> 
#include <string.h> 

int main(int argc, char **argv) {
    
   
	char p1[20] = {0}, p2[20] = {0};
	int op;

	// leitura da opção
	scanf("%d", &op);
	
	// leitura das palavras
	scanf("%s %s",p1,p2);

	switch(op){
		case 1:
			//compara os tamanhos das palavras 
			if (strlen(p1) > strlen(p2)){
				printf("1");
			}else{
				printf("2");
			}
		break;
		case 2:
			//coloca em ordem alfabetica
			if (strcmp(p1,p2) > 0){
				printf("1");
			}else{
				printf("2");
			}

		break;
		case 3:

		break;
		case 4:

		break;
		case 5:

		break;
	} 
} 
