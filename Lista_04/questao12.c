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

int* somaPorColunas_D(unsigned char** img, int nLin, int nCol);

int main (){
    srand(time(NULL));

    unsigned char **mat2D, *mat1D;
    int nLin=5, nCol=10;
    int* vet;
    mat1D = alocaImagem1D(nLin, nCol);
    mat2D = alocaImagem2D(mat1D, nLin, nCol);
    geraImgGrey_D (mat2D, nLin, nCol, 1);

    vet = somaPorColunas_D (mat2D, nLin, nCol);

    for (int i=0; i<nLin; i++){
        for (int j=0; j< nCol; j++){
            printf("%3u ", mat2D[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<nCol; i++){
        printf ("%d ", vet[i]);
    }

    free(mat1D);
    free(mat2D);
    free(vet);
    return 0;
}

int* somaPorColunas_D(unsigned char** img, int nLin, int nCol){
    int* vet;
    vet = (int*) calloc (nCol, sizeof(int));
    for (int i=0; i<nLin; i++){
        for (int j=0; j< nCol; j++){
            vet[j] += img[i][j];
        }
    }
    return vet;
}
