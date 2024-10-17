#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char* alocaImagem1D(int nLin, int nCol){
    return (unsigned char*) calloc(nLin*nCol, sizeof(unsigned char));
}

unsigned char** alocaImagem2D(unsigned char* img1D, int nLin, int nCol){
    unsigned char** img;
    img = (unsigned char**) calloc(nLin, sizeof(unsigned char*));
    for (int i=0; i<nLin; i++){
        img[i] = &img1D[i*nCol];
    }
    return img;
}

unsigned char geraGreyPixel (int tipo){
    int i = rand() % 101;
    if (tipo == 0){
        return rand() % 257;
    }
    else if (tipo > 0){
        if (i <= 75){
            return 128 + (rand() % 129); 
        }
        else{
            return rand() % 129;
        }
    }
    else{
        if (i <= 75){
            return rand() % 129;
        }
        else{
            return 128 + (rand() % 129);
        }
    }
}

void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo){
    for (int i=0; i<nLin; i++){
        for (int j=0; j< nCol; j++){
            img[i][j] = geraGreyPixel(tipo);
        }
    }
    return;
}

int pixelMax_D(unsigned char** img, int nLin, int nCol);

int main (){
    srand(time(NULL));

    unsigned char **mat2D, *mat1D, maior;
    int nLin=5, nCol=10;
    mat1D = alocaImagem1D(nLin, nCol);
    mat2D = alocaImagem2D(mat1D, nLin, nCol);
    geraImgGrey_D (mat2D, nLin, nCol, 1);

    maior = pixelMax_D(mat2D, nLin, nCol);

    for (int i=0; i<nLin; i++){
        for (int j=0; j< nCol; j++){
            printf("%3u ", mat2D[i][j]);
        }
        printf("\n");
    }

    printf("Maior: %u\n\n", maior);

    free(mat1D);
    free(mat2D);
    return 0;
}

int pixelMax_D(unsigned char** img, int nLin, int nCol){
    unsigned char maior = img[0][0];
    for (int i=0; i<nLin; i++){
        for (int j=0; j< nCol; j++){
            if(maior < img[i][j]){
                maior = img[i][j];
            }
        }
    }
    return maior;
}
