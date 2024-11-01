#include <stdio.h>
#include <stdlib.h>

int main (){
    int *vet;
    int qntd = 10;

    vet = (int*) malloc(qntd * sizeof(int));

    for (int i=0; i<qntd; i++){
        vet[i] = 10;
    }

    for (int i=0; i<qntd; i++){
        printf("%d\n", vet[i]);
    }



    free (vet);
    return 0;
}

