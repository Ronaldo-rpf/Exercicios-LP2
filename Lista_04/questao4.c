#include <stdio.h>
#include <stdlib.h>

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

void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char pixel);

int main (){
    unsigned char **mat2D, *mat1D;
    int nLin=5, nCol=10;
    mat1D = alocaImagem1D(nLin, nCol);
    mat2D = alocaImagem2D(mat1D, nLin, nCol);

    geraImgGreyFull_D (mat2D, nLin, nCol, 100);

    printf("%u\n\n", mat2D[4][9]);

    free(mat1D);
    free(mat2D);
    return 0;
}

void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char pixel){
    for (int i=0; i<nLin; i++){
        for(int j=0; j<nCol; j++){
            img[i][j] = pixel;
        }
    }
    return;
}
