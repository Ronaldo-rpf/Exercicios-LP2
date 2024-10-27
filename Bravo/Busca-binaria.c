#include <stdio.h>
#include <stdlib.h>

int vet[5] = {1,2,3,4,5};

int buscaBi_R (int x, int a, int b){
    if (a > b){
        return -1;
    }
    int meio = (a+b)/2;
    if(vet[meio] == x){
        return meio;
    }
    if (vet[meio] > x){
        return buscaBi_R(x, a, meio-1);
    }
    return buscaBi_R (x, meio+1, b);
}

int main (){
    printf("%d \n\n", buscaBi_R(5,0,4));
    return 0;
}
