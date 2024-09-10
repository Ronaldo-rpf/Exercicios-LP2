#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "imagens.h"

void geraImgGrey_R(unsigned char img[480][10], unsigned char tipo, int i, int j);
int somaPorTotal_R (unsigned char img[480][10], int i, int j, int soma);

int main() {
    srand(time(NULL));

    unsigned char img[480][10], tipo;
    int total;
    printf("Tipo: ");
    scanf("%cu", &tipo);

    geraImgGrey_R(img, tipo, 479, 9);

    total = somaPorTotal_R (img, 479, 9, 0);

    printf("Soma total: %d\n", total);

    return 0;
}

void geraImgGrey_R(unsigned char img[480][10], unsigned char tipo, int i, int j){
    if (j < 0){
        geraImgGrey_R(img, tipo, i - 1, 9);
        return;
    }
    if (i < 0){
        return;
    }
    img[i][j] = geraGreyPixel(tipo);
    geraImgGrey_R(img, tipo, i, j - 1);
}

int somaPorTotal_R (unsigned char img[480][10], int i, int j, int soma){
    if (j < 0){
        return somaPorTotal_R (img, i-1, 9, soma);
    }
    if (i < 0){
        return soma;
    }
    soma += img[i][j];
    return somaPorTotal_R (img, i, j-1, soma);
}

/*

int somaTotal(unsigned char img[I][J], int i, int j) {
    if (i < 0) {
        return 0;
    }
    if (j < 0) {
        return somaTotal(img, i - 1, J - 1);  
    }

    return img[i][j] + somaTotal(img, i, j - 1);  
}

*/
