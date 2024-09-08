#include <stdio.h>
#include <stdlib.h>

void geraImgGreyW_R(unsigned char img[480][10]);
void geraImgGreyW_Recursivo(unsigned char img[480][10], int i, int j);

int main (){
    unsigned char img[480][10];

    geraImgGreyW_R(img);

    for (int i = 0; i < 480; i++){
        for (int j = 0; j < 10; j++){
            printf("%3d ", img[i][j]);
        }
    }

    return 0;
}

void geraImgGreyW_R(unsigned char img[480][10]){
    geraImgGreyW_Recursivo(img, 479, 9);
}

void geraImgGreyW_Recursivo(unsigned char img[480][10], int i, int j){
    if (j < 0){
        geraImgGreyW_Recursivo(img, i - 1, 9);
        return;
    }
    if (i < 0){
        return;
    }
    img[i][j] = 255;
    geraImgGreyW_Recursivo(img, i, j - 1);
}
