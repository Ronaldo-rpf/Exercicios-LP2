#include <stdio.h>
#include <stdlib.h>

int a[4] = {2,4,-1,6};
int n = 4;

int min0 (int n){
    int temp;
    for (int i = 0; i < n; i++){
        if (a[0] > a[i]){
            temp = a[0];
            a[0] = a[i];
            a[i] = temp;
        }
    }
    return (a[0]);
}

int main (){
    int menor;
    for (int i = 0; i < n; i++){
        printf ("%d \n", a[i]);
    }
    menor = min0(n);
    printf("menor: %d\n", menor);

    for (int i = 0; i < n; i++){
        printf ("%d \n", a[i]);
    }
    return 0;
}

