#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    float a,b, result;

    scanf("%f", &a);
    scanf("%f", &b);
    result = pow(a,b);
    printf("%0.4f",result);

return 0;
}