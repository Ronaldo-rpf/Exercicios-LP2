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

int geraImgGrayFull(imgGray img, uchar pixel);

int geraImgRGBFull(imgRGB img, tRGB pixel);

int geraImgGrayB(imgGray img);

int main (){
    imgGray imagem;
    imagem = alocaImagemGray (5, 10);
    if(imagem._img == NULL || imagem.img == NULL){
        printf ("Erro ao alocar memoria.");
        return 1;
    }

    int aux;
    aux = geraImgGrayB (imagem);
    if (aux){
        printf ("Matriz preenchida corretamente.\n\n");
    }
    else{
        printf ("Erro ao preencher matriz.\n\n");    
    }

    free(imagem.img);
    free(imagem._img);
    return 0;
}

int geraImgGrayB(imgGray img){
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            img.img[i][j] = 0;
        }
    }

    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j] == 0){
                continue;
            }
            else{
                return -1;
            }
        }
    }
    return 1;
}

int geraImgRGBFull(imgRGB img, tRGB pixel){
    for (int i = 0; i < img.nLin*img.nCol; i++){
        img._img[i].R = pixel.R;
        img._img[i].B = pixel.B;
        img._img[i].G = pixel.G;
    }

    for (int i = 0; i < img.nLin*img.nCol; i++){
        if (img._img[i].R == pixel.R && img._img[i].B == pixel.B && img._img[i].G == pixel.G){
            continue;
        }
        else{
            return -1;
        }
    }
    return 1;
}

int geraImgGrayFull(imgGray img, uchar pixel){
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            img.img[i][j] = pixel;
        }
    }

    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img._img[i * img.nCol + j] == pixel){
                continue;
            }
            else{
                return -1;
            }
        }
    }
    return 1;
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

