#include <stdio.h>
#include <stdlib.h>
#include "imagens.h"

void geraImgGrey_R(unsigned char img[480][10], unsigned char tipo, int i, int j);
int pixelMax_R(unsigned char img[480][10], int maior, int i, int j);

int main () {
    unsigned char tipo, img[480][10];
    int m;

    printf("Tipo: ");
    scanf("%d", &tipo);

    geraImgGrey_R(img, tipo, 479, 9);
    m = pixelMax_R (img, -1, 479, 9);

    for (int i=0; i<480; i++){
        for (int j=0; j<10; j++){
            printf("%d\n", img[i][j]);
        }
    }

    printf("Maior: %d\n", m);

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

int pixelMax_R(unsigned char img[480][10], int maior, int i, int j){
    if (j < 0){
        return pixelMax_R(img, maior, i - 1, 9);
    }
    if (i < 0){
        return maior;
    }
    if (img[i][j] > maior){
        maior = img[i][j];
    }
    return pixelMax_R(img, maior, i, j - 1);
}
