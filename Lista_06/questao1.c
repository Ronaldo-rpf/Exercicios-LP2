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

int main (){
    imgGray imagem;
    imagem = alocaImagemGray(5,10);
    if(imagem._img == NULL || imagem.img == NULL){
        printf ("Erro ao alocar memoria.");
        return 1;
    }


    return 0;
}

imgGray alocaImagemGray(int nLin, int nCol){
    imgGray pic;
    pic._img = (uchar*) calloc (nLin*nCol, sizeof(uchar));
    pic.img = (uchar**) calloc (nLin, sizeof(uchar*));

    for (int i = 0; i < nLin; i++){
        pic.img[i] = &pic._img[i*nCol];
    }

    return pic;
}

