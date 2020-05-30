/*
	Autor: Wictor Dalbosco Silva
	N USP: 11871027

*/

#include <stdio.h>

int main(int argc, char **argv){

    double media, temp = 0;
    int mes, i;
    
    for(i = 0; i < 12; i++){
        scanf("%lf",&media);
        if (media > temp){
            temp = media;
            mes = i + 1;
        } 
    }
    
    printf("%d %0.2lf", mes, temp);

    return 0;
}