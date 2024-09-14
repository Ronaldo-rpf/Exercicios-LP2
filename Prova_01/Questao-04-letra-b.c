#include <stdio.h>
#include <stdlib.h>

int quantMaiorZerosR(float vet[], int n);

int main (){
    float vet[30] = {1, 2, 3, 25, 40, -20, -1, -90, 40};
    int qntd;

    qntd = quantMaiorZerosR (vet, 30);

    printf("%d elementos do vetor sao maiores do que 0.\n\n", qntd);

    return 0;
}

int quantMaiorZerosR(float vet[], int n){
    if (n==0){
        return 0;
    }
    if (vet[n-1] > 0){
        return 1 + quantMaiorZerosR(vet, n-1);
    }
    return quantMaiorZerosR(vet, n-1);
}
