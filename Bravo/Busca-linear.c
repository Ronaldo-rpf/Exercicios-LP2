#include <stdio.h>
#include <stdlib.h>

int a[5] = {1,2,3,4,5};

int buscaLi_R (int x, int n){
    if (n==-1){
        return -1;
    }
    if (a[n] == x){
        return n;
    }
    return buscaBi_R (x, n-1);
}

int main (){
    printf("%d \n\n", buscaLi_R(5,4));
    return 0;
}
