#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int num;
    int den;
    double valor;
}frac;

frac* geraRandomArray (int tam);

int main (){
    srand (time(NULL));
    frac *vet = geraRandomArray(10);

    for (int i = 0; i < 10; i++){
        printf("Numerador: %d \nDenominador: %d \nValor da fracao: %f\n\n", vet[i].num, vet[i].den, vet[i].valor);
    }

    free(vet);
    return 0;
}

frac* geraRandomArray (int tam){
    frac *vet = (frac*) calloc (tam, sizeof(frac));
    for (int i = 0; i < tam; i++){
        vet[i].num = (rand() % 201) - 100;
        vet[i].den = (rand() % 201) - 100;
        if (vet[i].den == 0){
            vet[i].valor = 1000000;
        }
        else{
            vet[i].valor = (double) vet[i].num / vet[i].den;
        }
    }
    return vet;
}