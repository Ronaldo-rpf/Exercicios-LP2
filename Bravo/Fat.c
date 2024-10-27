#include <stdio.h>
#include <stdlib.h>

int fat (int n){
    if (n==0){
        return 1;
    }
    int m = fat(n-1);
    return (n*m);
}

int fatorial (int n){
    if (n==0){
        return 1;
    }
    for (int i = n-1; i != 0; i--){
        n *= i;
    }
    return n;
}

int main (){
    printf("%d \n\n", fat(4));

    printf("%d \n\n", fatorial(4));
    return 0;
}