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

void geraImgGreyW_D(unsigned char** img, int nLin, int nCol);

int main (){
    unsigned char **mat2D, *mat1D;
    int nLin=5, nCol=10;
    mat1D = alocaImagem1D(nLin, nCol);
    mat2D = alocaImagem2D(mat1D, nLin, nCol);

    geraImgGreyW_D (mat2D, nLin, nCol);

    printf("%u\n\n", mat2D[0][0]);

    free(mat1D);
    free(mat2D);
    return 0;
}

void geraImgGreyW_D(unsigned char** img, int nLin, int nCol){
    for (int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            img[i][j] = 255;
        }
    }
    return;
}
