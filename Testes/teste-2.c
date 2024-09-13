#include <stdio.h>
#include <stdlib.h>

int quantZeros (int vet[], int n);

int main (){
    int vet[20] = {1, 2, 3, 4 ,5 ,6 ,7 ,8};
    int aux;

    aux = quantZeros(vet, 20);

    printf("%d", aux);






    return 0;
}

int quantZeros (int vet[], int n){
    int cont=0;
    for (int i=0; i < n; i++){
        if (vet[i] != 0){
            cont++;
        }
    }
    return cont;
}