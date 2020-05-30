#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, char **argv){
	double a, b;
	char op;
	
	scanf("%lf %c %lf", &a, &op, &b);
        
	switch(op){
		case '+':
			printf("%lf\n", a+b);
		break;
		case '-':
			printf("%lf\n", a-b);
		break;
		case '*': 
			printf("%lf\n", a*b);
		break;
		case '/': 
			printf("%lf\n", a/b);
		break;
		case '%':
			printf("%lf\n", (a/b)*100);
		break;
		default:
		break;
	}
}