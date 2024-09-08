#include <stdio.h>
#include <stdlib.h>

void geraImgGreyFull_R (unsigned char img[480][10], unsigned char pixel, int x, int y);

int main (){
    unsigned char img[480][10], pixel = 10;

    geraImgGreyFull_R(img, pixel, 479, 9);

    printf("%u", img[270][1]);

    return 0;
}

void geraImgGreyFull_R(unsigned char img[480][10], unsigned char pixel, int x, int y){
    if (y < 0){
        geraImgGreyFull_R(img, pixel, x-1, 9);
        return;
    }
    if (x < 0){
        return;
    }
    img[x][y] = pixel;
    geraImgGreyFull_R(img, pixel, x, y-1);
}
