#include <stdio.h>
#include <stdlib.h>

int quantMaiorZeros(float vet[], int n);

int main (){
    float vet[30] = {1, 2, 3, 25, 40, -20, -1, -90, 40};
    int qntd;

    qntd = quantMaiorZeros (vet, 30);

    printf("%d elementos do vetor sao maiores do que 0.\n\n", qntd);

    return 0;
}

int quantMaiorZeros(float vet[], int n){
    int i, cont=0;
    for (i = 0; i < n; i++){
        if (vet[i] > 0){
            cont++;
        }
    }
    return cont;
}