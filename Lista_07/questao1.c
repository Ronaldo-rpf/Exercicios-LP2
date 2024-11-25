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

//---------------------------------------------------------------------------------------------------------------------------------------------

imgGray alocaImagemGray (int nLin, int nCol);

imgRGB alocaImagemRGB (int nLin, int nCol);

int saveImgGray (imgGray img, char desc[], char fileName[]);

int main (){
    imgGray picgray;
    imgRGB picRGB;
    picgray = alocaImagemGray (5, 10);
    if (picgray.img == NULL || picgray._img == NULL){
        printf("Erro ao alocar imagem Gray.\n\n");
        return 1;
    }
    picRGB = alocaImagemRGB (5, 10);
    if (picRGB._img == NULL || picRGB.img == NULL){
        printf ("Erro ao alocar imagem RGB.\n\n");
        return 1;
    }





    printf ("Fim do programa.");
    free (picRGB._img);
    free (picRGB.img);
    free (picgray._img);
    free (picgray.img);
    return 0;
}

imgGray alocaImagemGray (int nLin, int nCol){
    imgGray picture;
    picture.nCol = nCol;
    picture.nLin = nLin;
    picture._img = NULL;
    picture.img = NULL;
    picture._img = (uchar*) calloc (nLin * nCol, sizeof(uchar));
    picture.img = (uchar**) calloc (nLin, sizeof(uchar*));
    if (picture._img == NULL || picture.img == NULL){
        return picture;
    }
    for (int i = 0; i < nLin; i++){
        picture.img[i] = &picture._img[i * nCol];
    } 
    return picture;
}

imgRGB alocaImagemRGB (int nLin, int nCol){
    imgRGB pic;
    pic.nLin = nLin;
    pic.nCol = nCol;
    pic._img = NULL;
    pic .img = NULL;
    pic._img = (tRGB*) calloc (nLin * nCol, sizeof(tRGB));
    pic.img = (tRGB**) calloc (nLin, sizeof(tRGB*));
    if (pic._img == NULL || pic.img == NULL){
        return pic;
    }
    for (int i = 0; i < nLin; i++){
        pic.img[i] = &pic._img[i * nCol];
    }
    return pic;
}

