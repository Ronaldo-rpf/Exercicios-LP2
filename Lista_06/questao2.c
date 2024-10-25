#include <stdio.h>
#include <stdlib.h>

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

struct imagens{
    imgGray img;
    struct imagens *prox;
};

typedef struct imagens tImagens;

//FUNÇÕES----------------------------------------------------------------------------------------------

imgGray alocaImagemGray(int nLin, int nCol);

imgRGB alocaImagemRGB(int nLin, int nCol);

int main (){
    imgRGB imagem;
    imagem = alocaImagemRGB (5, 10);
    if(imagem._img == NULL || imagem.img == NULL){
        printf ("Erro ao alocar memoria.");
        return 1;
    }

    free(imagem.img);
    free(imagem._img);
    return 0;
}

imgRGB alocaImagemRGB(int nLin, int nCol){
    imgRGB pic;
    pic.nLin = nLin;
    pic.nCol = nCol;
    pic._img = (tRGB*) calloc (nLin*nCol, sizeof(tRGB));
    pic.img = (tRGB**) calloc (nLin, sizeof(tRGB*));
    
    for (int i = 0; i < nLin; i++){
        pic.img[i] = &pic._img[i*nCol];
    }

    return pic;
}

imgGray alocaImagemGray(int nLin, int nCol){
    imgGray pic;
    pic.nLin = nLin;
    pic.nCol = nCol;
    pic._img = (uchar*) calloc (nLin*nCol, sizeof(uchar));
    pic.img = (uchar**) calloc (nLin, sizeof(uchar*));

    for (int i = 0; i < nLin; i++){
        pic.img[i] = &pic._img[i*nCol];
    }

    return pic;
}

