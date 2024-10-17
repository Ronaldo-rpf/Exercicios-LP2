#include <stdio.h>
#include <stdlib.h>

unsigned char* alocaImagem1D(int nLin, int nCol){
    return (unsigned char*) calloc(nLin*nCol, sizeof(unsigned char));
}

void geraImgGreyB_D(unsigned char* img, int nLin, int nCol);

int main (){
    unsigned char *mat1D;
    int nLin=5, nCol=10;
    mat1D = alocaImagem1D(nLin, nCol);

    geraImgGreyB_D (mat1D, nLin, nCol);

    printf("%u\n\n", mat1D[0]);

    free(mat1D);
    return 0;
}

void geraImgGreyB_D(unsigned char* img, int nLin, int nCol){
    for (int i=0; i<nLin*nCol; i++){
            img[i] = 0;
    }
    return;
}
