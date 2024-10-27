#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

unsigned char geraGreyPixel (int tipo);

imgGray alocaImagemGray(int nLin, int nCol);

imgRGB alocaImagemRGB(int nLin, int nCol);

int geraImgGrayFull(imgGray img, uchar pixel);

int geraImgRGBFull(imgRGB img, tRGB pixel);

int geraImgGrayB(imgGray img);

int geraImgRGBB(imgRGB img);

int geraImgGrayW(imgGray img);

int geraImgRGBW(imgRGB img);

int geraImgGray(imgGray img, int tipo);

int geraImgRGB(imgRGB img, int tipo);

int pixelGrayMax(imgGray img);

int pixelGrayMin(imgGray img);

tRGB pixelRGBMax(imgRGB img);

tRGB pixelRGBMin(imgRGB img);

int* somaPorLinhasGray(imgGray img);

int* somaPorColunasGray(imgGray img);

tRGB* somaPorLinhasRGB(imgRGB img);

tRGB* somaPorColunasRGB(imgRGB img);

int somaTotalGray(imgGray img);

tRGB somaTotalRGB(imgRGB img);

int quantosPixelsGrayNaInt(imgGray img, uchar inten);

int main (){
    srand(time(NULL));
    imgGray imagem;
    imagem = alocaImagemGray (5, 10);
    if(imagem._img == NULL || imagem.img == NULL){
        printf ("Erro ao alocar memoria.");
        return 1;
    }
    int aux;
    aux = geraImgGray (imagem, 1);
    if (aux){
        printf ("Matriz preenchida corretamente.\n\n");
    }
    else{
        printf ("Erro ao preencher matriz.\n\n");    
    }
    
    int inten, cont;
    printf("Qual pixel deseja contar?\n");
    scanf("%d", &inten);
    cont = quantosPixelsGrayNaInt (imagem, inten);
    printf("Quantidade de pixels iguais a %d na imagem: %d\n\n", inten, cont);

    free(imagem.img);
    free(imagem._img);
    return 0;
}

int quantosPixelsGrayNaInt(imgGray img, uchar inten){
    int cont=0;
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j] == inten){
                cont++;
            }
        }
    }
    return cont;
}

tRGB somaTotalRGB(imgRGB img){
    tRGB *vetL, soma;
    soma.R = 0;
    soma.G = 0;
    soma.B = 0;
    vetL = somaPorLinhasRGB (img);
    for (int i = 0; i < img.nLin; i++){
        soma.R += vetL[i].R;
        soma.G += vetL[i].G;
        soma.B += vetL[i].B;
    }
    return soma;
}

int somaTotalGray(imgGray img){
    int *vetL, soma = 0;
    vetL = somaPorLinhasGray (img);
    for (int i = 0; i < img.nLin; i++){
        soma += vetL[i];
    }
    return soma;
}

tRGB* somaPorColunasRGB(imgRGB img){
    tRGB *vet = (tRGB*) calloc (img.nCol, sizeof(tRGB));
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            vet[j].R += img.img[i][j].R;
            vet[j].G += img.img[i][j].G;
            vet[j].B += img.img[i][j].B;
        }
    }
    return vet;
}

tRGB* somaPorLinhasRGB(imgRGB img){
    tRGB *vet = (tRGB*) calloc (img.nLin, sizeof(tRGB));
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            vet[i].R += img.img[i][j].R;
            vet[i].G += img.img[i][j].G;
            vet[i].B += img.img[i][j].B;
        }
    }
    return vet;
}

int* somaPorColunasGray(imgGray img){
    int *vet = (int*) calloc (img.nCol, sizeof(int));
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            vet[j] += img.img[i][j];
        }
    }
    return vet;
}

int* somaPorLinhasGray(imgGray img){
    int *vet = (int*) calloc (img.nLin, sizeof(int));
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            vet[i] += img.img[i][j];
        }
    }
    return vet;
}

tRGB pixelRGBMin(imgRGB img){
    tRGB menor;
    menor.R = img.img[0][0].R;
    menor.G = img.img[0][0].G;
    menor.B = img.img[0][0].B;
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j].R < menor.R){
                menor.R = img.img[i][j].R;
            }
            if (img.img[i][j].G < menor.G){
                menor.G = img.img[i][j].G;
            }
            if (img.img[i][j].B < menor.B){
                menor.B = img.img[i][j].B;
            }
        }
    }
    return menor;
}

tRGB pixelRGBMax(imgRGB img){
    tRGB maior;
    maior.R = img.img[0][0].R;
    maior.G = img.img[0][0].G;
    maior.B = img.img[0][0].B;
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j].R > maior.R){
                maior.R = img.img[i][j].R;
            }
            if (img.img[i][j].G > maior.G){
                maior.G = img.img[i][j].G;
            }
            if (img.img[i][j].B > maior.B){
                maior.B = img.img[i][j].B;
            }
        }
    }
    return maior;
}

int pixelGrayMin(imgGray img){
    int menor = img.img[0][0];
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j] < menor){
                menor = img.img[i][j];
            }
        }
    }
    return menor;
}

int pixelGrayMax(imgGray img){
    int maior = img.img[0][0];
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j] > maior){
                maior = img.img[i][j];
            }
        }
    }
    return maior;
}

int geraImgRGB(imgRGB img, int tipo){
    int cont=0;
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            img.img[i][j].B = geraGreyPixel(tipo);
            img.img[i][j].R = geraGreyPixel(tipo);
            img.img[i][j].G = geraGreyPixel(tipo);
            cont += 3;
        }
    }

    if (cont == img.nCol*img.nLin*3){
        return 1;
    }
    else{
        return -1;
    }
}

int geraImgGray(imgGray img, int tipo){
    int cont=0;
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            img.img[i][j] = geraGreyPixel (tipo);
            cont++;
        }
    }

    if (cont == img.nLin*img.nCol){
        return 1;
    }
    else{
        return -1;
    }
}

int geraImgGrayW(imgGray img){
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            img.img[i][j] = 255;
        }
    }

    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j] == 255){
                continue;
            }
            else{
                return -1;
            }
        }
    }
    return 1;
}

int geraImgRGBW(imgRGB img){
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            img.img[i][j].B = 255;
            img.img[i][j].R = 255;
            img.img[i][j].G = 255;
        }
    }

    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j].R == 255 && img.img[i][j].G == 255 && img.img[i][j].B == 255){
                continue;
            }
            else{
                return -1;
            }
        }
    }
    return 1;
}

int geraImgRGBB(imgRGB img){
    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            img.img[i][j].B = 0;
            img.img[i][j].R = 0;
            img.img[i][j].G = 0;
        }
    }

    for (int i = 0; i < img.nLin; i++){
        for (int j = 0; j < img.nCol; j++){
            if (img.img[i][j].R == 0 && img.img[i][j].G == 0 && img.img[i][j].B == 0){
                continue;
            }
            else{
                return -1;
            }
        }
    }
    return 1;
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