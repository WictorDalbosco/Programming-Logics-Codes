#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){

	int a,temp,i,prox = 0;
	
	scanf("%d",&a);
	
	for(i=1;i < a; i++){
		if((pow(i,2)+i)/2==a){
			temp = 1;
			prox = (pow((i+1),2)+(i+1))/2;
			break;
		}else{
			temp = 0;
		}
	}
	
	if(temp == 1){
		printf("SIM \n");
		printf("%d \n",prox);
		printf("SIM");
	}else{
		printf("NAO");
	}
	
	return 0;
}