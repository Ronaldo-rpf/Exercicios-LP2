#include <stdio.h>
#include <stdlib.h>

void geraImgGreyFull_R (unsigned char img, unsigned char pixel);

int main (){
    unsigned char pixel, img[480][640];

    printf("Pixel: ");
    scanf("%u", &pixel);

    geraImgGreyFull_R(img, pixel);


    return 0;
}

void geraImgGreyFull_R (unsigned char img[480][640], unsigned char pixel){
    for (int i, i<480, i++){
        for (int j, j<640, j++){
            img[i][j] = pixel;
        }
    }
}