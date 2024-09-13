#include <stdio.h>
#include <stdlib.h>

int quantZerosR(int vet[], int n);

int main (){
    int vet[20] = {1, 2, 3, 4 ,5 ,6 ,7 };
    int aux;

    aux = quantZerosR(vet, 20);

    printf("%d", aux);






    return 0;
}

int quantZerosR (int vet[], int n){
    if (n==0){
        return 0;
    }
    if (vet[n-1] != 0){
        return 1 + quantZerosR (vet, n-1);
    }
    else{
        return quantZerosR(vet, n-1);
    }
}
