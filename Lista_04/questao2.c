#include <stdio.h>
#include <stdlib.h>

unsigned char* alocaImagem1D(int nLin, int nCol){
    return (unsigned char*) calloc(nLin*nCol, sizeof(unsigned char));
}

unsigned char** alocaImagem2D(unsigned char* img1D, int nLin, int nCol);

int main (){
    unsigned char **img2D, *img1D;
    int nLin=5, nCol=10;
    img1D = alocaImagem1D(nLin, nCol);

    img2D = alocaImagem2D(img1D, nLin, nCol);

    printf ("%u\n\n", img2D[1][4]);

    printf("%u\n\n", img1D[10]);

    free(img2D);
    free(img1D);
    return 0;
}

unsigned char** alocaImagem2D(unsigned char* img1D, int nLin, int nCol){
    unsigned char** img;
    img = (unsigned char**) calloc(nLin, sizeof(unsigned char*));
    for (int i=0; i<nLin; i++){
        img[i] = &img1D[i*nCol];
    }
    return img;
}