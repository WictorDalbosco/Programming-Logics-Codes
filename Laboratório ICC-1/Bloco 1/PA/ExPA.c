#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){
     long long int a,b,c,an,soma;

    scanf("%lld %lld %lld",&a,&b,&c);
	
	an = a+(c-1)*b;
	soma = ((a+an)*c)/2;
	
	printf("%lld \n",an);
    printf("%lld",soma);
	
	return 0;
}