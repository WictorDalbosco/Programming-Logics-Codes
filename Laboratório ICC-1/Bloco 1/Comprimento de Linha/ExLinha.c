#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){
    int a, i = 0;
	float vetor[a*2], comprimento = 0;
	
	scanf("%d",&a);
		
	for(i = 0;i < (2*a); i++){
		scanf("%f",vetor[i]);
	}
	
	while(i < a*2 && i+1 != (a*2)-1 ){
		comprimento = comprimento + sqrt(pow((vetor[i+2]-vetor[i]),2)+pow((vetor[i+3]-vetor[i+1]),2));
		i =i+2;
	}
	
	printf("%0.4f",comprimento);
		
	 
	return 0;
}