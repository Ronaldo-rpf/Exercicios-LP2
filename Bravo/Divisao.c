#include <stdio.h>
#include <stdlib.h>

int divisao (int q, int x, int y){
    if (x < y){
        return q;
    }
    int m = divisao(q+1, x-y, y);
    return m;
}

int main (){
    printf("%d \n\n", divisao(0,100,23));
    return 0;
}

