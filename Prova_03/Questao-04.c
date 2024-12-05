#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char** carregaImagem (int* col, int* lin, char* fileName);

int main (){
    unsigned char **pic;
    char *nome = (char*) calloc (80, sizeof(char));
    int lin, col;

    printf ("Qual o nome do arquivo que sera lido (sem extensao)?\n");
    scanf ("%s", nome);

    pic = carregaImagem (&col, &lin, nome);
    if (pic == NULL){
        printf ("Erro ao carregar imagem do arquivo.\n\n");
    }
    else{
        printf ("Imagem carregada com sucesso:\n\n");
        printf ("Linhas: %d\nColunas: %d\n", lin, col);
        for (int i = 0; i < lin; i++){
            for (int j = 0; j < col; j++){
                printf ("%03u ", pic[i][j]);
            }
            printf ("\n");
        }
    }

    free (nome);
    for (int i = 0; i < 10; i++){
        free (pic[i]);
    }
    free (pic);
    return 0;
}

unsigned char** carregaImagem (int* col, int* lin, char* fileName){
    strcat (fileName, ".img");
    unsigned char **img;

    FILE *arq;
    arq = fopen (fileName, "rb");
    if (arq == NULL){
        img = NULL;
        return img;
    }
    img = (unsigned char**) calloc (10, sizeof(unsigned char*));
    for (int i = 0; i < 10; i++){
        img[i] = (unsigned char*) calloc (10, sizeof(unsigned char));
    }
    
    if (fread(lin, sizeof(int), 1, arq) != 1){
        img = NULL;
        return img;
    }
    if (fread(col, sizeof(int), 1, arq) != 1){
        img = NULL;
        return img;
    }
    for (int i = 0; i < (*lin); i++){
        for (int j = 0; j < (*col); j++){
            if (fread(&img[i][j], sizeof(unsigned char), 1, arq) != 1){
                img = NULL;
                return img;
            }
        }
    }
    int aux = fclose (arq);
    if (aux){
        img = NULL;
        return img;
    }
    return img;
}
