#include <stdio.h>
#include <stdlib.h>

int guardaImagem (unsigned char** img, int lin, int col, char* fileName);

unsigned char** carregaImagem (int *lin, int *col, char *fileName);

int criarBinario (int *vet);

int main (){
    int vet[10] = {1,2,3,4,4,5,6,8};
    int aux = criarBinario (vet);
    if (aux){
        printf("Rquivo binario criado om sus.\n\n");
    }
    else{
        printf("error ao criar.\n\n");
    }

    return 0;
}

int guardaImagem (unsigned char** img, int lin, int col, char* fileName){
    FILE *arq;
    arq = fopen(fileName, "w");
    if (arq){
        fprintf(arq, "%d %d\n", lin, col);
        for (int i=0; i<lin; i++){
            for (int j=0; j<col; j++){
                fprintf (arq, "%3u ", img[i][j]);
            }
            fprintf(arq, "\n");
        }
        int aux = fclose(arq);
        if (aux){
            return 0;
        }
        return 1;
    }
    else{
        return 0;
    }
}

unsigned char** carregaImagem (int *lin, int *col, char *fileName){
    FILE *arq;
    arq = fopen (fileName, "r");
    if (arq){
        fscanf (arq, "%u ", lin);
        fscanf (arq, "%u\n", col);
        unsigned char** pic;
        pic = (unsigned char**) calloc (*lin, sizeof(unsigned char*));
        for (int i=0; i<*lin; i++){
            pic[i] = (unsigned char*) calloc(*col, sizeof(unsigned char));
        }

        for (int i=0; i<*lin; i++){
            for (int j=0; j<*col; j++){
                fscanf(arq, "%3u ", &pic[i][j]);
            }
        }

        int aux = fclose(arq);
        if (aux){
            pic = NULL;
            for (int i=0; i<*lin; i++){
                pic[i] = NULL;
            }
            return pic;
        }
        else{
            return pic;
        }
    }
    else{
        return NULL;
    }
}

int criarBinario (int *vet){
    FILE *arq;
    arq = fopen("binario.txt", "wb");
    if (arq){
        if (fwrite (vet, sizeof(int), 10, arq) == 10){
            int aux = fclose(arq);
            if (aux){
                return 0;
            }
            return 1;
        }
        else{
            return 0;
        }
    } 
    else{
        return 0;
    }
}