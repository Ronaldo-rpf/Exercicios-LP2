#include <stdio.h>
#include <stdlib.h>

int quantosPares (int vet[], int n);

int main (){
    int vet[10] = {1,2,3,4,5,6,40,100,101,467}, qntd;

    qntd = quantosPares(vet, 10);

    printf("O vetor possui %d numeros pares.\n\n", qntd);



    return 0;
}


int quantosPares (int vet[], int n){
    int i, cont = 0;
    for (i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            cont++;
        }
    }
    return cont;
}
