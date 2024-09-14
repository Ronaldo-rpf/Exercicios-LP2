#include <stdio.h>
#include <stdlib.h>

int quantosParesR (int vet[], int n);

int main (){
    int vet[10] = {1,2,3,4,5,6,40,100,101,467}, qntd;

    qntd = quantosParesR(vet, 10);

    printf("O vetor possui %d numeros pares.\n\n", qntd);



    return 0;
}


int quantosParesR (int vet[], int n){
    if (n==0){
        return 0;
    }
    if (vet[n-1] % 2 == 0){
        return 1 + quantosParesR(vet, n-1);
    }
    return quantosParesR(vet, n-1);
}
