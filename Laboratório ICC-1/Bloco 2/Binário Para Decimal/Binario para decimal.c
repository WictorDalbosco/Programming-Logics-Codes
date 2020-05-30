#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
    
    int i;
    long long int decimal, binario, temp, r;
    
    scanf("%lld", &binario);
    
    temp = binario;
    
    decimal = 0;
    
    for(i = 0;temp > 0; i++){
        r = temp % 10;
        decimal = decimal + (r * pow(2,i));
        temp = temp/10;
    }
    
    
    printf("%lld", decimal);
    
    return 0;
}