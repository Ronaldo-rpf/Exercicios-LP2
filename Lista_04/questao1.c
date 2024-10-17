#include <stdio.h>
#include <stdlib.h>

unsigned char* alocaImagem1D(int nLin, int nCol);

int main (){
    int nLin = 5, nCol = 10;
    unsigned char* img; 
    img = alocaImagem1D(nLin, nCol);

    for (int i =0, aux=0; i<50; i++, aux++){
        if (aux==5){
            printf("\n");
            aux=0;
        }
        printf ("%3u", img[i]);
        
    }


    return 0;
}

unsigned char* alocaImagem1D(int nLin, int nCol){
    return (unsigned char*) calloc(nLin*nCol, sizeof(unsigned char));
}