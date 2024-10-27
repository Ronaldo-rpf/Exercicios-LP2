#include <stdio.h>
#include <stdlib.h>

int a[4] = {2,4,-1,6};
int n = 4;

int min0_R (int n){
    if (n==0){
        return (a[0]);
    }
    if (a[0] > a[n-1]){
        int temp = a[0];
        a[0] = a[n-1];
        a[n-1] = temp;
    }
    return min0_R (n-1);
}

int main (){
    int menor;
    for (int i = 0; i < n; i++){
        printf ("%d \n", a[i]);
    }
    menor = min0_R(n);
    printf("menor: %d\n", menor);

    for (int i = 0; i < n; i++){
        printf ("%d \n", a[i]);
    }
    return 0;
}

