#include <stdio.h>

int main(int argc, char **argv){
    /*char c;
    unsigned int x;
    short int y;
    int z;
    long int w;
    unsigned long int u;
    long long int v;
    float f;
    double t;
    long double q;
    */


    printf("%lu \n", sizeof(char));
    printf("%lu \n", sizeof(unsigned int));
    printf("%lu \n", sizeof(short int));
    printf("%lu \n", sizeof(int));
    printf("%lu \n", sizeof(long int));
    printf("%lu \n", sizeof(unsigned long int));
    printf("%lu \n", sizeof(long long int));
    printf("%lu \n", sizeof(float));
    printf("%ld \n", sizeof(double));
    printf("%ld \n", sizeof(long double));


return 0;
}