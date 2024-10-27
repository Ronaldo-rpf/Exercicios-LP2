#include <stdio.h>
#include <stdlib.h>

int a[4] = {2,4,-1,6};
int n = 4;

int max0_R (int n){
    if (n==0){
        return (a[0]);
    }
    if (a[0] < a[n-1]){
        int temp = a[0];
        a[0] = a[n-1];
        a[n-1] = temp;
    }
    return max0_R(n-1);
}

int main (){
    int maior;
    for (int i = 0; i < n; i++){
        printf ("%d \n", a[i]);
    }
    maior = max0_R(n);
    printf("Maior: %d\n", maior);
    for (int i = 0; i < n; i++){
        printf ("%d \n", a[i]);
    }
    return 0;
}

