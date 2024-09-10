#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "imagens.h"

void geraImgGrey_R(unsigned char img[480][10], unsigned char tipo, int i, int j);
int quantosPixelsNaInt_R(unsigned char img[480][10], int i, int j, unsigned char inteiro);

int main() {
    srand(time(NULL));

    unsigned char img[480][10], tipo;
    int qntd;

    printf("Tipo: ");
    scanf("%cu", &tipo);

    geraImgGrey_R(img, tipo, 479, 9);

    qntd = quantosPixelsNaInt_R(img, 479, 9, 255);

    for (int i=0; i<480;i++){
        for (int j=0; j< 10; j++){
            printf("%d", img[i][j]);
        }
        printf("\n");
    }

    printf("Quantidade: %d\n", qntd);

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

int quantosPixelsNaInt_R (unsigned char img[480][10], int i, int j, unsigned char inteiro){
    if (j < 0){
        return quantosPixelsNaInt_R(img, i-1, 9, inteiro);
    }
    if (i < 0){
        return 0;
    }
    if (inteiro == img[i][j]){
        return 1 + quantosPixelsNaInt_R (img, i, j-1, inteiro);
    }
    else{
        return quantosPixelsNaInt_R (img, i, j-1, inteiro);
    }
}
