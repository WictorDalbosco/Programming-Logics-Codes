#include<stdio.h>
#include<math.h>

int main(int argc, char **argv){
    double a,b,c,d, media, menor;

    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

    if(a <= b && a <= c && a <= d ){
        menor = a;
    }else if( b <= a && b <= c && b <= d){
        menor = b;
    }else if( c <= a && c <= b && c <= d){
        menor = c;
    }else if( d <= a && d <= b && d <= c){
        menor = d;
    }
    media = ((a+b+c+d)-menor)/3;

    printf("%0.4lf",media);
}