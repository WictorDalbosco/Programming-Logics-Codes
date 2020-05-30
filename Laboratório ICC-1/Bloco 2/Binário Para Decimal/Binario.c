#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    
	// b -> número binario
	// base[] -> vetor com as bases decimais para a soma
	char b, base[30];
	
	base[30] = {pow(2,29), pow(2,28), pow(2,27), pow(2,26), pow(2,25), pow(2,24), pow(2,23), pow(2,22), pow(2,21), pow(2,20),
				pow(2,19), pow(2,18), pow(2,17), pow(2,16), pow(2,15), pow(2,14), pow(2,13), pow(2,12), pow(2,11), pow(2,10),
				pow(2,8), pow(2,7), pow(2,6), pow(2,5), pow(2,4), pow(2,3), pow(2,2), pow(2,1), pow(2,0)}
	
	printf("%d",base[29]);


return 0;
}