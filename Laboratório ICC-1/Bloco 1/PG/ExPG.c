#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
     float a,b,c,an,soma;

    scanf("%f %f %f",&a,&b,&c);
	
	an = a*pow(b,(c-1));
	soma = (a*(pow(b,c)-1))/(b-1);
	
	printf("%0.2f \n",an);
    printf("%0.2f",soma);
	
}