#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    int ano;

    scanf("%d",&ano);
    if((ano % 4 == 0  && ano % 100 != 0)|| ano % 400 == 0){
        printf("SIM");
    }else{
        printf("NAO");
    }

return 0;
}
