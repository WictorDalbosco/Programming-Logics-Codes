#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){
    int a,b,c;
	
	scanf("%d %d %d",&a,&b,&c);
	
	if(a == 0 || b==0 || c ==0){
		printf("NAO");
	}else{
		if((pow(a,2)+pow(b,2)==pow(c,2))||(pow(b,2)+pow(c,2)==pow(a,2))||(pow(a,2)+pow(c,2)==pow(b,2))){
			printf("SIM");
		}else{
			printf("NAO");
		}
	}
		
	 
	return 0;
}