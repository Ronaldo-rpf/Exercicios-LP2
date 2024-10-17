#include <stdio.h>
#include <stdlib.h>

unsigned char* alocaImagem1D(int nLin, int nCol){
    return (unsigned char*) calloc(nLin*nCol, sizeof(unsigned char));
}

void geraImgGreyFull_D(unsigned char* img, int nLin, int nCol, unsigned char pixel);

int main (){
    unsigned char* mat;
    int nLin=5, nCol=10;
    mat = alocaImagem1D(nLin, nCol);

    geraImgGreyFull_D (mat, nLin, nCol, 100);

    printf("%u\n\n", mat[0]);

    free(mat); 
    return 0;
}

void geraImgGreyFull_D(unsigned char* img, int nLin, int nCol, unsigned char pixel){
    for (int i=0; i<nLin*nCol; i++){
        img[i] = pixel;
    }
    return;
}
