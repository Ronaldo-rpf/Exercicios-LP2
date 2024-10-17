#include <stdio.h>
#include <stdlib.h>

int buscaBinaria (int *vet, int indice, int elemento);

int main (){
    int aux, elemento;
    int *vet;

    vet = (int*) calloc (100, sizeof(int));

    for (int i=0; i<100; i++){
        vet[i] = i;
    }

    printf("Qual elemento deseja procurar?\n");
    scanf("%d", &elemento);

    aux = buscaBinaria(vet, 99, elemento);

    if (aux == -1){
        printf ("elemento nao encontrado.\n\n");
    }
    else{
        printf("Elemento encontrado: %d\n\n", aux);
    }
    
    free (vet);
    return 0;
}

int buscaBinaria (int *vet, int indice, int elemento){
    int atual = -300, meio, inicioV = 0, fimV = indice;
    while (elemento != atual){
        meio = (inicioV + fimV)/2;
        atual = vet[meio];
        if (elemento > atual){
            inicioV = meio + 1;
        }
        if (elemento < atual){
            fimV = meio - 1;
        }
        if (inicioV > fimV){
            return -1;
        }
    }
    printf ("Encontrado na posicao %d\n\n", meio);
    return atual;
}
