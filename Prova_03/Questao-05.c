#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int quantosCaracteres (char *fileName);
int geraArtigo (char *fileName, int tam);

int main (){
    srand (time(NULL));
    char *nomeArtigo = (char*) calloc (40, sizeof(char));
    int tamanhoArtigo = 1100 + rand() % 201, aux;

    printf ("Qual sera o nome do arquivo com o resumo (sem extensao)?\n");
    scanf ("%s", nomeArtigo);
    aux = geraArtigo (nomeArtigo, tamanhoArtigo);
    if (aux){
        printf ("Arquivo de texto com o resumo criado com sucesso.\n\n");
    }
    else{
        printf ("Erro ao criar arquivo com o resumo.\n\n");
    }

    aux = quantosCaracteres (nomeArtigo);
    if (aux == -1){
        printf ("Erro ao tentar ler arquivo.\n\n");
    }
    else if (aux == 0){
        printf ("Limite de caracteres excedido.\n\n");
    }
    else{
        printf ("Quantidade total de caracteres: %d\n\n", aux);
    }

    free (nomeArtigo);
    return 0;
}

int quantosCaracteres (char *fileName){
    FILE *arq = fopen (fileName, "r");
    if (arq == NULL){
        return -1;
    }
    int cont = 0;
    char letras;
    while (fscanf (arq, "%c", &letras) == 1){
        cont++;
        if (cont > 1200){
            fclose (arq);
            return 0;
        }
    }

    int aux = fclose (arq);
    if (aux){
        return -1;
    }
    return cont;
}

int geraArtigo (char *fileName, int tam){
    strcat (fileName, ".txt");
    FILE *arq = fopen (fileName, "w");
    if (arq == NULL){
        return 0;
    }
    for (int i = 0; i < tam; i++){
        fprintf (arq, "%c", 97 + rand() % 26);
    }
    int aux = fclose (arq);
    if (aux){
        return 0;
    }
    return 1;
}
