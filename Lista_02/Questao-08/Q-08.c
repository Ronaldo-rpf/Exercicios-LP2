#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "imagens.h"

void somaPorLinhas_R(unsigned char img[480][10], int soma[480], int i, int j, int aux);
void geraImgGrey_R(unsigned char img[480][10], unsigned char tipo, int i, int j);

int main() {
    srand(time(NULL));

    unsigned char img[480][10], tipo;
    int soma[480] = {0};
    printf("Tipo: ");
    scanf("%cu", &tipo);

    geraImgGrey_R(img, tipo, 479, 9);

    printf("Soma: ");
    somaPorLinhas_R(img, soma, 479, 9, 479);

    printf("%d\n\n", soma[1]);

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

void somaPorLinhas_R(unsigned char img[480][10], int soma[480], int i, int j, int aux){
    if (j < 0){
        somaPorLinhas_R(img, soma, i-1, 9, aux-1);
        return;
    }
    if (i < 0){
        return;
    }    
    soma[aux] += img[i][j];
    somaPorLinhas_R(img, soma, i, j-1, aux);
}
