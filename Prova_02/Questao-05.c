#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uchar;

typedef struct{
    uchar R, G, B;
}tRGB;

typedef struct{
    uchar *_img;
    uchar **img;
    int nLin, nCol;
}imgGray;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

imgRGB geraRandomImage (int nLin, int nCol);

imgGray convert (imgRGB img);

int main (){
    srand(time(NULL));
    imgRGB img = geraRandomImage(3, 5);
    printf ("Imagem formada de forma aleatoria (RGB): \n\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf ("(%3u, %3u, %3u)  ", img.img[i][j].R, img.img[i][j].G, img.img[i][j].B);
        }
        printf("\n");
    }

    imgGray picgray = convert(img);

    printf("\nImagem covertida para tons de cinza: \n\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf ("%3u ", picgray.img[i][j]);
        }
        printf("\n");
    }

    return 0;
}

imgGray convert (imgRGB img){
    imgGray pic;
    pic.nLin = img.nLin;
    pic.nCol = img.nCol;
    pic._img = NULL;
    pic.img = NULL;
    pic._img = (uchar*) calloc (pic.nLin*pic.nCol, sizeof(uchar));
    pic.img = (uchar**) calloc (pic.nLin, sizeof(uchar*));
    if (pic._img == NULL || pic.img == NULL){
        return pic;
    }
    for (int i = 0; i < pic.nLin; i++){
        pic.img[i] = &pic._img[i * pic.nCol];
    }
    for (int i = 0; i < pic.nLin * pic.nCol; i++){
        pic._img[i] = 0.299 * img._img[i].R + 0.587 * img._img[i].G + 0.114 * img._img[i].B;
    }
    return pic;
}

imgRGB geraRandomImage (int nLin, int nCol){
    imgRGB pic;
    pic.nLin = nLin;
    pic.nCol = nCol;
    pic._img = NULL;
    pic.img = NULL;
    pic._img = (tRGB*) calloc (nLin*nCol, sizeof(tRGB));
    pic.img = (tRGB**) calloc (nLin, sizeof(tRGB*));
    if (pic._img == NULL || pic.img == NULL){
        return pic;
    }
    for (int i = 0; i < nLin; i++){
        pic.img[i] = &pic._img[i * nCol];
    }
    for (int i = 0; i < nLin * nCol; i++){
        pic._img[i].R = rand() % 256;
        pic._img[i].G = rand() % 256;
        pic._img[i].B = rand() % 256;
    }
    return pic;
}