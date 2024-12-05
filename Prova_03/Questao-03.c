#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int guardaImagem (unsigned char** img, int lin, int col, char* fileName);

int main (){
    srand (time(NULL));
    unsigned char **pic;
    pic = (unsigned char**) calloc (10, sizeof(unsigned char*));
    for (int i = 0; i < 10; i++){
        pic[i] = (unsigned char*) calloc (10, sizeof(unsigned char));
    }
    char *nome = (char*) calloc (80, sizeof(char));

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            pic[i][j] = rand() % 256;
        }
    }

    printf ("Qual sera o nome do arquivo (sem extensao)?\n");
    scanf ("%s", nome);

    int aux = guardaImagem (pic, 10, 10, nome);
    if (aux){
        printf ("Arquivo criado com sucesso!\n\n");
    }
    else{
        printf ("Erro ao criar arquivo.\n\n");
    }

    free (nome);
    for (int i = 0; i < 10; i++){
        free (pic[i]);
    }
    free (pic);
    return 0;
}

int guardaImagem (unsigned char** img, int lin, int col, char* fileName){
    strcat (fileName, ".img");
    FILE *arq;
    arq = fopen (fileName, "wb");
    if (arq == NULL){
        return 0;
    }
    if (fwrite(&lin, sizeof(int), 1, arq) != 1){
        fclose(arq);
        return 0;
    }
    if (fwrite(&col, sizeof(int), 1, arq) != 1){
        fclose(arq);
        return 0;
    }
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            if (fwrite(&img[i][j], sizeof(unsigned char), 1, arq) != 1){
                fclose(arq);
                return 0;
            }
        }
    }
    int aux = fclose (arq);
    if (aux){
        return 0;
    }
    return 1;
}
