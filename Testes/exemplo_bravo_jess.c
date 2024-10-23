#include <stdio.h>
#include <stdlib.h>

int main (){
    int vet[10] = {4,6,2,100,5,6,7,8,9,10};
    int i=0, temp, n=5;

    while(i < n){
        if (vet[0] < vet[i]){
            temp = vet[0];
            vet[0] = vet[i];
            vet[i] = temp;
        }
        i++;
    }

    return 0;
}
