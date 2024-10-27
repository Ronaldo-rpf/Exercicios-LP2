#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uchar;

typedef struct{
    uchar R, G, B;
}tRGB;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin,nCol;
}imgRGB;

imgRGB alocaImagemRGB(int nLin, int nCol);
unsigned char geraGreyPixel(int tipo);
int geraImgRGB(imgRGB img, int tipo);
tRGB* somaPorLinhasRGB(imgRGB img);

int main(void) {
    srand(time(NULL));
    int nLin,nCol;
    int tipo = 1;
    imgRGB img;
    tRGB* somaLINHA;

    printf("Insira o valor da linha e coluna:\n");
    scanf("%d %d",&nLin, &nCol);

    printf("\n");

    img = alocaImagemRGB(nLin,nCol);
    geraImgRGB(img,tipo);
    somaLINHA = somaPorLinhasRGB(img);

    printf("Matriz:\n");

    for(int i = 0; i < nLin; i++) {
        for(int j = 0; j < nCol; j++){
            printf("(%03d, %03d, %03d) ", img.img[i][j].R, img.img[i][j].G, img.img[i][j].B);
            if (i<nLin) {
                printf(" ");
            }
            if (j==nCol-1) {
                printf("\n");
            }
        }
    }

    printf("\n");

    printf("\nA soma dos elementos da Matriz por Linha:\n");
    for(int i = 0; i < nLin; i++) {
        printf("Linha %d: (%03d, %03d, %03d)\n", i+1,somaLINHA[i].R,somaLINHA[i].G,somaLINHA[i].B);
    }
    printf("\n");

    free(img.img);
    free(img._img);

    return 0;
}

imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB img1D;
    img1D.nLin = nLin;
    img1D.nCol = nCol;
    img1D._img = NULL;
    img1D.img = NULL;

    img1D._img = (tRGB*)calloc(nLin * nCol,sizeof(tRGB));
    if(img1D._img == NULL) {
        return img1D;
    }

    img1D.img = (tRGB*)calloc(nLin,sizeof(tRGB));
    if (img1D.img == NULL) {
        free(img1D._img);
        img1D._img = NULL;
        return img1D;
    }

    for(int i = 0; i < nLin; i++) {        
        img1D.img[i] = &img1D._img[i * nCol]; 
    }

    return img1D;
}

unsigned char geraGreyPixel(int tipo) {
    int prct = rand () % 100 + 1;

    if (tipo<0) {
        if (prct<=75) {
            return rand() % 129; 
        }
        else {
            return rand() % (256 - 128) + 128;
        }
    }
    
    else if (tipo>0) {
        if (prct<=75) {
            return rand() % (256 - 128) + 128; 
        }
        else {
            return rand() % 129; 
        }
    }
    
    else {
        return rand() % 256;
    }
}

int geraImgRGB(imgRGB img, int tipo) {
    int iTotal = img.nLin * img.nCol;

    if(img.img == NULL) {
        return 0;
    }

    for(int i = 0; i < iTotal; i++) {
        img._img[i].R = geraGreyPixel(tipo);
        img._img[i].G = geraGreyPixel(tipo);
        img._img[i].B = geraGreyPixel(tipo);
    }

    return 1;
}

tRGB* somaPorLinhasRGB(imgRGB img) {
    int I = img.nLin;
    int J = img.nCol;
    tRGB* somaLINHA = (tRGB*)calloc(I,sizeof(tRGB));

    for (int i  = 0; i < I; i++) {
        for(int j = 0; j < J; j++) {
            somaLINHA[i].R += img.img[i][j].R;
            somaLINHA[i].G += img.img[i][j].G;
            somaLINHA[i].B += img.img[i][j].B;
        }
    }
    return somaLINHA;
}