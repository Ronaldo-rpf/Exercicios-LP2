#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int geraGreyPixel (int);
void geraLinhaR (int *, int, int);

int main (){
    int tipo;
    int vet[640];
    srand (time(NULL));

    printf ("Tipo 0, todas com a mesma probabilidade.\nTipo > 0, mais claras tem maior probabilidade.\nTipo < 0, mais escurar maior probabilidade.\n");
    printf("Tipo escolhido: ");
    scanf("%d", &tipo);
    
    geraLinhaR(vet, 640, tipo);

    //apagar:
    for (int i = 0; i < 640; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}

void geraLinhaR (int vet[], int n, int tipo){
    if (n == 0){
        return;
    }
    vet[n-1] = geraGreyPixel(tipo);
    geraLinhaR(vet, n-1, tipo);
}

int geraGreyPixel (int tipo){
    int i = rand() % 101;
    if (tipo == 0){
        return rand() % 257;
    }
    if (tipo > 0){
        if (i <= 75){
            return 128 + (rand() % 129); 
        }
        return rand() % 129;
    }
    if (tipo < 0){
        if (i <= 75){
            return rand() % 129;
        }
        return 128 + (rand() % 129);
    }
    return 1; //to tentando de tudo
}