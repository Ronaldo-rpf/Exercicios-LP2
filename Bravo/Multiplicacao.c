#include <stdio.h>
#include <stdlib.h>

int mult (int x, int y){
    if (y==0){
        return 0;
    }
    int m = mult (x, y-1);
    return (x + m);
}

int main (){
    printf("%d \n\n", mult(4,3));
    return 0;
}

int mult (int x, int y){
    if (y==0){
        return 0;
    }
    return x + mult (x, y-1);
}
