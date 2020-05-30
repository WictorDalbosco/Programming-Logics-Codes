#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    float a;
    scanf("%f", &a);

    printf("%d \n", (int)a);
    printf("%0.4f \n",a-(int)a);
    printf("%0.0f \n", round(a));
return 0;
}