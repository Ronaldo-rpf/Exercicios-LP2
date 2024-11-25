#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int aux;
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
    char *desc, *fileName;
    desc = (char*) calloc (80, sizeof(char));
    fileName = (char*) calloc (30, sizeof(char));
    printf ("Descricao da imagem: ");
    fgets (desc, 80, stdin);
    fflush(stdin);
    printf ("Nome do arquivo: ");
    fgets (fileName, 30, stdin);
    aux = saveImgGray (picgray, desc, fileName);

    if (aux){
        printf ("Arquivo criado com sucesso.\n\n");
    }
    else{
        printf ("Erro ao criar arquivo.\n\n");
    }

    printf ("Fim do programa.");
    free (fileName);
    free (desc);
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

int saveImgGray (imgGray img, char desc[], char fileName[]){
    char *nomeArq = (char*) malloc (80 * sizeof(char));
    strcpy (nomeArq, fileName);
    strcat (nomeArq, ".hed");
    FILE *arq;
    arq = fopen (fileName, "w");
    if (arq){
        fprintf (arq, "Tipo da imagem: Gray\n");
        fprintf (arq, "Linhas: %d - Colunas: %d\n", img.nLin, img.nCol);
        fprintf (arq, "%s", desc);
        fclose (arq);
        free (nomeArq);
        return 1;
    }
    else{
        perror ("Erro ao abrir arquivo.\n\n");
        free (nomeArq);
        return 0;
    }
}

        //fprintf (arq, "Arquivo onde estao as intensidades: "");